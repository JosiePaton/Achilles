/* File: xsecmodule.c
 * This file is auto-generated with f2py (version:2).
 * f2py is a Fortran to Python Interface Generator (FPIG), Second Edition,
 * written by Pearu Peterson <pearu@cens.ioc.ee>.
 * Generation date: Tue Dec 24 15:44:39 2019
 * Do not edit this file directly unless you know what you are doing!!!
 */

#ifdef __cplusplus
extern "C" {
#endif

/*********************** See f2py2e/cfuncs.py: includes ***********************/
#include "Python.h"
#include "fortranobject.h"
#include <stdarg.h>
/*need_includes0*/

/**************** See f2py2e/rules.py: mod_rules['modulebody'] ****************/
static PyObject *xsec_error;
static PyObject *xsec_module;

/*********************** See f2py2e/cfuncs.py: typedefs ***********************/
/*need_typedefs*/

/****************** See f2py2e/cfuncs.py: typedefs_generated ******************/
/*need_typedefs_generated*/

/********************** See f2py2e/cfuncs.py: cppmacros **********************/
#if defined(PREPEND_FORTRAN)
#if defined(NO_APPEND_FORTRAN)
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f, F) _##F
#else
#define F_FUNC(f, F) _##f
#endif
#else
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f, F) _##F##_
#else
#define F_FUNC(f, F) _##f##_
#endif
#endif
#else
#if defined(NO_APPEND_FORTRAN)
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f, F) F
#else
#define F_FUNC(f, F) f
#endif
#else
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f, F) F##_
#else
#define F_FUNC(f, F) f##_
#endif
#endif
#endif
#if defined(UNDERSCORE_G77)
#define F_FUNC_US(f, F) F_FUNC(f##_, F##_)
#else
#define F_FUNC_US(f, F) F_FUNC(f, F)
#endif

#define rank(var) var##_Rank
#define shape(var, dim) var##_Dims[dim]
#define old_rank(var) (PyArray_NDIM((PyArrayObject *)(capi_##var##_tmp)))
#define old_shape(var, dim) PyArray_DIM(((PyArrayObject *)(capi_##var##_tmp)), dim)
#define fshape(var, dim) shape(var, rank(var) - dim - 1)
#define len(var) shape(var, 0)
#define flen(var) fshape(var, 0)
#define old_size(var) PyArray_SIZE((PyArrayObject *)(capi_##var##_tmp))
/* #define index(i) capi_i ## i */
#define slen(var) capi_##var##_len
#define size(var, ...) f2py_size((PyArrayObject *)(capi_##var##_tmp), ##__VA_ARGS__, -1)

#ifdef DEBUGCFUNCS
#define CFUNCSMESS(mess) fprintf(stderr, "debug-capi:" mess);
#define CFUNCSMESSPY(mess, obj)                            \
    CFUNCSMESS(mess)                                       \
    PyObject_Print((PyObject *)obj, stderr, Py_PRINT_RAW); \
    fprintf(stderr, "\n");
#else
#define CFUNCSMESS(mess)
#define CFUNCSMESSPY(mess, obj)
#endif

#ifndef max
#define max(a, b) ((a > b) ? (a) : (b))
#endif
#ifndef min
#define min(a, b) ((a < b) ? (a) : (b))
#endif
#ifndef MAX
#define MAX(a, b) ((a > b) ? (a) : (b))
#endif
#ifndef MIN
#define MIN(a, b) ((a < b) ? (a) : (b))
#endif

/************************ See f2py2e/cfuncs.py: cfuncs ************************/
static int f2py_size(PyArrayObject *var, ...) {
    npy_int sz = 0;
    npy_int dim;
    npy_int rank;
    va_list argp;
    va_start(argp, var);
    dim = va_arg(argp, npy_int);
    if(dim == -1) {
        sz = PyArray_SIZE(var);
    } else {
        rank = PyArray_NDIM(var);
        if(dim >= 1 && dim <= rank)
            sz = PyArray_DIM(var, dim - 1);
        else
            fprintf(stderr,
                    "f2py_size: 2nd argument value=%d fails to satisfy 1<=value<=%d. Result will "
                    "be 0.\n",
                    dim, rank);
    }
    va_end(argp);
    return sz;
}

static int double_from_pyobj(double *v, PyObject *obj, const char *errmess) {
    PyObject *tmp = NULL;
    if(PyFloat_Check(obj)) {
#ifdef __sgi
        *v = PyFloat_AsDouble(obj);
#else
        *v = PyFloat_AS_DOUBLE(obj);
#endif
        return 1;
    }
    tmp = PyNumber_Float(obj);
    if(tmp) {
#ifdef __sgi
        *v = PyFloat_AsDouble(tmp);
#else
        *v = PyFloat_AS_DOUBLE(tmp);
#endif
        Py_DECREF(tmp);
        return 1;
    }
    if(PyComplex_Check(obj))
        tmp = PyObject_GetAttrString(obj, "real");
    else if(PyString_Check(obj) || PyUnicode_Check(obj))
        /*pass*/;
    else if(PySequence_Check(obj))
        tmp = PySequence_GetItem(obj, 0);
    if(tmp) {
        PyErr_Clear();
        if(double_from_pyobj(v, tmp, errmess)) {
            Py_DECREF(tmp);
            return 1;
        }
        Py_DECREF(tmp);
    }
    {
        PyObject *err = PyErr_Occurred();
        if(err == NULL) err = xsec_error;
        PyErr_SetString(err, errmess);
    }
    return 0;
}

static int int_from_pyobj(int *v, PyObject *obj, const char *errmess) {
    PyObject *tmp = NULL;
    if(PyInt_Check(obj)) {
        *v = (int)PyInt_AS_LONG(obj);
        return 1;
    }
    tmp = PyNumber_Int(obj);
    if(tmp) {
        *v = PyInt_AS_LONG(tmp);
        Py_DECREF(tmp);
        return 1;
    }
    if(PyComplex_Check(obj))
        tmp = PyObject_GetAttrString(obj, "real");
    else if(PyString_Check(obj) || PyUnicode_Check(obj))
        /*pass*/;
    else if(PySequence_Check(obj))
        tmp = PySequence_GetItem(obj, 0);
    if(tmp) {
        PyErr_Clear();
        if(int_from_pyobj(v, tmp, errmess)) {
            Py_DECREF(tmp);
            return 1;
        }
        Py_DECREF(tmp);
    }
    {
        PyObject *err = PyErr_Occurred();
        if(err == NULL) err = xsec_error;
        PyErr_SetString(err, errmess);
    }
    return 0;
}

/********************* See f2py2e/cfuncs.py: userincludes *********************/
/*need_userincludes*/

/********************* See f2py2e/capi_rules.py: usercode *********************/

/* See f2py2e/rules.py */
extern void F_FUNC(cc1, CC1)(double *, double *, double *, double *, double *, double *, double *,
                             double *, int *, double *);
extern void F_FUNC(sigccc, SIGCCC)(double *, int *);
/*eof externroutines*/

/******************** See f2py2e/capi_rules.py: usercode1 ********************/

/******************* See f2py2e/cb_rules.py: buildcallback *******************/
/*need_callbacks*/

/*********************** See f2py2e/rules.py: buildapi ***********************/

/************************************ cc1 ************************************/
static char doc_f2py_rout_xsec_cc1[] = "\
sig = cc1(xq,w,wt,xk,xp,phi,ee0,theta,ig)\n\nWrapper for ``cc1``.\
\n\nParameters\n----------\n"
                                       "xq : input float\n"
                                       "w : input float\n"
                                       "wt : input float\n"
                                       "xk : input float\n"
                                       "xp : input float\n"
                                       "phi : input float\n"
                                       "ee0 : input float\n"
                                       "theta : input float\n"
                                       "ig : input int\n"
                                       "\nReturns\n-------\n"
                                       "sig : rank-1 array('d') with bounds (2)";
/* extern void
 * F_FUNC(cc1,CC1)(double*,double*,double*,double*,double*,double*,double*,double*,int*,double*); */
static PyObject *
f2py_rout_xsec_cc1(const PyObject *capi_self, PyObject *capi_args, PyObject *capi_keywds,
                   void (*f2py_func)(double *, double *, double *, double *, double *, double *,
                                     double *, double *, int *, double *)) {
    PyObject *volatile capi_buildvalue = NULL;
    volatile int f2py_success = 1;
    /*decl*/

    double xq = 0;
    PyObject *xq_capi = Py_None;
    double w = 0;
    PyObject *w_capi = Py_None;
    double wt = 0;
    PyObject *wt_capi = Py_None;
    double xk = 0;
    PyObject *xk_capi = Py_None;
    double xp = 0;
    PyObject *xp_capi = Py_None;
    double phi = 0;
    PyObject *phi_capi = Py_None;
    double ee0 = 0;
    PyObject *ee0_capi = Py_None;
    double theta = 0;
    PyObject *theta_capi = Py_None;
    int ig = 0;
    PyObject *ig_capi = Py_None;
    double *sig = NULL;
    npy_intp sig_Dims[1] = {-1};
    const int sig_Rank = 1;
    PyArrayObject *capi_sig_tmp = NULL;
    int capi_sig_intent = 0;
    static char *capi_kwlist[] = {"xq", "w", "wt", "xk", "xp", "phi", "ee0", "theta", "ig", NULL};

/*routdebugenter*/
#ifdef F2PY_REPORT_ATEXIT
    f2py_start_clock();
#endif
    if(!PyArg_ParseTupleAndKeywords(capi_args, capi_keywds, "OOOOOOOOO:xsec.cc1", capi_kwlist,
                                    &xq_capi, &w_capi, &wt_capi, &xk_capi, &xp_capi, &phi_capi,
                                    &ee0_capi, &theta_capi, &ig_capi))
        return NULL;
    /*frompyobj*/
    /* Processing variable xq */
    f2py_success = double_from_pyobj(&xq, xq_capi,
                                     "xsec.cc1() 1st argument (xq) can't be converted to double");
    if(f2py_success) {
        /* Processing variable w */
        f2py_success = double_from_pyobj(
            &w, w_capi, "xsec.cc1() 2nd argument (w) can't be converted to double");
        if(f2py_success) {
            /* Processing variable wt */
            f2py_success = double_from_pyobj(
                &wt, wt_capi, "xsec.cc1() 3rd argument (wt) can't be converted to double");
            if(f2py_success) {
                /* Processing variable xk */
                f2py_success = double_from_pyobj(
                    &xk, xk_capi, "xsec.cc1() 4th argument (xk) can't be converted to double");
                if(f2py_success) {
                    /* Processing variable xp */
                    f2py_success = double_from_pyobj(
                        &xp, xp_capi, "xsec.cc1() 5th argument (xp) can't be converted to double");
                    if(f2py_success) {
                        /* Processing variable phi */
                        f2py_success = double_from_pyobj(
                            &phi, phi_capi,
                            "xsec.cc1() 6th argument (phi) can't be converted to double");
                        if(f2py_success) {
                            /* Processing variable ee0 */
                            f2py_success = double_from_pyobj(
                                &ee0, ee0_capi,
                                "xsec.cc1() 7th argument (ee0) can't be converted to double");
                            if(f2py_success) {
                                /* Processing variable theta */
                                f2py_success = double_from_pyobj(
                                    &theta, theta_capi,
                                    "xsec.cc1() 8th argument (theta) can't be converted to double");
                                if(f2py_success) {
                                    /* Processing variable ig */
                                    f2py_success = int_from_pyobj(
                                        &ig, ig_capi,
                                        "xsec.cc1() 9th argument (ig) can't be converted to int");
                                    if(f2py_success) {
                                        /* Processing variable sig */
                                        sig_Dims[0] = 2;
                                        capi_sig_intent |= F2PY_INTENT_OUT | F2PY_INTENT_HIDE;
                                        capi_sig_tmp =
                                            array_from_pyobj(NPY_DOUBLE, sig_Dims, sig_Rank,
                                                             capi_sig_intent, Py_None);
                                        if(capi_sig_tmp == NULL) {
                                            if(!PyErr_Occurred())
                                                PyErr_SetString(xsec_error,
                                                                "failed in converting hidden `sig' "
                                                                "of xsec.cc1 to C/Fortran array");
                                        } else {
                                            sig = (double *)(PyArray_DATA(capi_sig_tmp));

/*end of frompyobj*/
#ifdef F2PY_REPORT_ATEXIT
                                            f2py_start_call_clock();
#endif
                                            /*callfortranroutine*/
                                            (*f2py_func)(&xq, &w, &wt, &xk, &xp, &phi, &ee0, &theta,
                                                         &ig, sig);
                                            if(PyErr_Occurred()) f2py_success = 0;
#ifdef F2PY_REPORT_ATEXIT
                                            f2py_stop_call_clock();
#endif
                                            /*end of callfortranroutine*/
                                            if(f2py_success) {
                                                /*pyobjfrom*/
                                                /*end of pyobjfrom*/
                                                CFUNCSMESS("Building return value.\n");
                                                capi_buildvalue = Py_BuildValue("N", capi_sig_tmp);
                                                /*closepyobjfrom*/
                                                /*end of closepyobjfrom*/
                                            } /*if (f2py_success) after callfortranroutine*/
                                              /*cleanupfrompyobj*/
                                        }     /*if (capi_sig_tmp == NULL) ... else of sig*/
                                        /* End of cleaning variable sig */
                                    } /*if (f2py_success) of ig*/
                                    /* End of cleaning variable ig */
                                } /*if (f2py_success) of theta*/
                                /* End of cleaning variable theta */
                            } /*if (f2py_success) of ee0*/
                            /* End of cleaning variable ee0 */
                        } /*if (f2py_success) of phi*/
                        /* End of cleaning variable phi */
                    } /*if (f2py_success) of xp*/
                    /* End of cleaning variable xp */
                } /*if (f2py_success) of xk*/
                /* End of cleaning variable xk */
            } /*if (f2py_success) of wt*/
            /* End of cleaning variable wt */
        } /*if (f2py_success) of w*/
        /* End of cleaning variable w */
    } /*if (f2py_success) of xq*/
    /* End of cleaning variable xq */
    /*end of cleanupfrompyobj*/
    if(capi_buildvalue == NULL) {
        /*routdebugfailure*/
    } else {
        /*routdebugleave*/
    }
    CFUNCSMESS("Freeing memory.\n");
/*freemem*/
#ifdef F2PY_REPORT_ATEXIT
    f2py_stop_clock();
#endif
    return capi_buildvalue;
}
/********************************* end of cc1 *********************************/

/*********************************** sigccc ***********************************/
static char doc_f2py_rout_xsec_sigccc[] = "\
sig = sigccc(ig)\n\nWrapper for ``sigccc``.\
\n\nParameters\n----------\n"
                                          "ig : input int\n"
                                          "\nReturns\n-------\n"
                                          "sig : float";
/* extern void F_FUNC(sigccc,SIGCCC)(double*,int*); */
static PyObject *f2py_rout_xsec_sigccc(const PyObject *capi_self, PyObject *capi_args,
                                       PyObject *capi_keywds, void (*f2py_func)(double *, int *)) {
    PyObject *volatile capi_buildvalue = NULL;
    volatile int f2py_success = 1;
    /*decl*/

    double sig = 0;
    int ig = 0;
    PyObject *ig_capi = Py_None;
    static char *capi_kwlist[] = {"ig", NULL};

/*routdebugenter*/
#ifdef F2PY_REPORT_ATEXIT
    f2py_start_clock();
#endif
    if(!PyArg_ParseTupleAndKeywords(capi_args, capi_keywds, "O:xsec.sigccc", capi_kwlist, &ig_capi))
        return NULL;
    /*frompyobj*/
    /* Processing variable sig */
    /* Processing variable ig */
    f2py_success =
        int_from_pyobj(&ig, ig_capi, "xsec.sigccc() 1st argument (ig) can't be converted to int");
    if(f2py_success) {
/*end of frompyobj*/
#ifdef F2PY_REPORT_ATEXIT
        f2py_start_call_clock();
#endif
        /*callfortranroutine*/
        (*f2py_func)(&sig, &ig);
        if(PyErr_Occurred()) f2py_success = 0;
#ifdef F2PY_REPORT_ATEXIT
        f2py_stop_call_clock();
#endif
        /*end of callfortranroutine*/
        if(f2py_success) {
            /*pyobjfrom*/
            /*end of pyobjfrom*/
            CFUNCSMESS("Building return value.\n");
            capi_buildvalue = Py_BuildValue("d", sig);
            /*closepyobjfrom*/
            /*end of closepyobjfrom*/
        } /*if (f2py_success) after callfortranroutine*/
          /*cleanupfrompyobj*/
    }     /*if (f2py_success) of ig*/
    /* End of cleaning variable ig */
    /* End of cleaning variable sig */
    /*end of cleanupfrompyobj*/
    if(capi_buildvalue == NULL) {
        /*routdebugfailure*/
    } else {
        /*routdebugleave*/
    }
    CFUNCSMESS("Freeing memory.\n");
/*freemem*/
#ifdef F2PY_REPORT_ATEXIT
    f2py_stop_clock();
#endif
    return capi_buildvalue;
}
/******************************* end of sigccc *******************************/

/***************************** dirac_matrices_in *****************************/
static char doc_f2py_rout_xsec_dirac_matrices_dirac_matrices_in[] = "\
dirac_matrices_in(xmn_in)\n\nWrapper for ``dirac_matrices_in``.\
\n\nParameters\n----------\n"
                                                                    "xmn_in : input float";
/*  */
static PyObject *f2py_rout_xsec_dirac_matrices_dirac_matrices_in(const PyObject *capi_self,
                                                                 PyObject *capi_args,
                                                                 PyObject *capi_keywds,
                                                                 void (*f2py_func)(double *)) {
    PyObject *volatile capi_buildvalue = NULL;
    volatile int f2py_success = 1;
    /*decl*/

    double xmn_in = 0;
    PyObject *xmn_in_capi = Py_None;
    static char *capi_kwlist[] = {"xmn_in", NULL};

/*routdebugenter*/
#ifdef F2PY_REPORT_ATEXIT
    f2py_start_clock();
#endif
    if(!PyArg_ParseTupleAndKeywords(capi_args, capi_keywds,
                                    "O:xsec.dirac_matrices.dirac_matrices_in", capi_kwlist,
                                    &xmn_in_capi))
        return NULL;
    /*frompyobj*/
    /* Processing variable xmn_in */
    f2py_success = double_from_pyobj(&xmn_in, xmn_in_capi,
                                     "xsec.dirac_matrices.dirac_matrices_in() 1st argument "
                                     "(xmn_in) can't be converted to double");
    if(f2py_success) {
/*end of frompyobj*/
#ifdef F2PY_REPORT_ATEXIT
        f2py_start_call_clock();
#endif
        /*callfortranroutine*/
        (*f2py_func)(&xmn_in);
        if(PyErr_Occurred()) f2py_success = 0;
#ifdef F2PY_REPORT_ATEXIT
        f2py_stop_call_clock();
#endif
        /*end of callfortranroutine*/
        if(f2py_success) {
            /*pyobjfrom*/
            /*end of pyobjfrom*/
            CFUNCSMESS("Building return value.\n");
            capi_buildvalue = Py_BuildValue("");
            /*closepyobjfrom*/
            /*end of closepyobjfrom*/
        } /*if (f2py_success) after callfortranroutine*/
          /*cleanupfrompyobj*/
    }     /*if (f2py_success) of xmn_in*/
    /* End of cleaning variable xmn_in */
    /*end of cleanupfrompyobj*/
    if(capi_buildvalue == NULL) {
        /*routdebugfailure*/
    } else {
        /*routdebugleave*/
    }
    CFUNCSMESS("Freeing memory.\n");
/*freemem*/
#ifdef F2PY_REPORT_ATEXIT
    f2py_stop_clock();
#endif
    return capi_buildvalue;
}
/************************** end of dirac_matrices_in **************************/

/******************************* define_spinors *******************************/
static char doc_f2py_rout_xsec_dirac_matrices_define_spinors[] = "\
define_spinors()\n\nWrapper for ``define_spinors``.\
\n";
/*  */
static PyObject *f2py_rout_xsec_dirac_matrices_define_spinors(const PyObject *capi_self,
                                                              PyObject *capi_args,
                                                              PyObject *capi_keywds,
                                                              void (*f2py_func)(void)) {
    PyObject *volatile capi_buildvalue = NULL;
    volatile int f2py_success = 1;
    /*decl*/

    static char *capi_kwlist[] = {NULL};

/*routdebugenter*/
#ifdef F2PY_REPORT_ATEXIT
    f2py_start_clock();
#endif
    if(!PyArg_ParseTupleAndKeywords(capi_args, capi_keywds, ":xsec.dirac_matrices.define_spinors",
                                    capi_kwlist))
        return NULL;
/*frompyobj*/
/*end of frompyobj*/
#ifdef F2PY_REPORT_ATEXIT
    f2py_start_call_clock();
#endif
    /*callfortranroutine*/
    (*f2py_func)();
    if(PyErr_Occurred()) f2py_success = 0;
#ifdef F2PY_REPORT_ATEXIT
    f2py_stop_call_clock();
#endif
    /*end of callfortranroutine*/
    if(f2py_success) {
        /*pyobjfrom*/
        /*end of pyobjfrom*/
        CFUNCSMESS("Building return value.\n");
        capi_buildvalue = Py_BuildValue("");
        /*closepyobjfrom*/
        /*end of closepyobjfrom*/
    } /*if (f2py_success) after callfortranroutine*/
      /*cleanupfrompyobj*/
      /*end of cleanupfrompyobj*/
    if(capi_buildvalue == NULL) {
        /*routdebugfailure*/
    } else {
        /*routdebugleave*/
    }
    CFUNCSMESS("Freeing memory.\n");
/*freemem*/
#ifdef F2PY_REPORT_ATEXIT
    f2py_stop_clock();
#endif
    return capi_buildvalue;
}
/*************************** end of define_spinors ***************************/

/******************************** current_init ********************************/
static char doc_f2py_rout_xsec_dirac_matrices_current_init[] =
    "\
current_init(p1_in,pp1_in,q_in)\n\nWrapper for ``current_init``.\
\n\nParameters\n----------\n"
    "p1_in : input rank-1 array('d') with bounds (4)\n"
    "pp1_in : input rank-1 array('d') with bounds (4)\n"
    "q_in : input rank-1 array('d') with bounds (4)";
/*  */
static PyObject *
f2py_rout_xsec_dirac_matrices_current_init(const PyObject *capi_self, PyObject *capi_args,
                                           PyObject *capi_keywds,
                                           void (*f2py_func)(double *, double *, double *)) {
    PyObject *volatile capi_buildvalue = NULL;
    volatile int f2py_success = 1;
    /*decl*/

    double *p1_in = NULL;
    npy_intp p1_in_Dims[1] = {-1};
    const int p1_in_Rank = 1;
    PyArrayObject *capi_p1_in_tmp = NULL;
    int capi_p1_in_intent = 0;
    PyObject *p1_in_capi = Py_None;
    double *pp1_in = NULL;
    npy_intp pp1_in_Dims[1] = {-1};
    const int pp1_in_Rank = 1;
    PyArrayObject *capi_pp1_in_tmp = NULL;
    int capi_pp1_in_intent = 0;
    PyObject *pp1_in_capi = Py_None;
    double *q_in = NULL;
    npy_intp q_in_Dims[1] = {-1};
    const int q_in_Rank = 1;
    PyArrayObject *capi_q_in_tmp = NULL;
    int capi_q_in_intent = 0;
    PyObject *q_in_capi = Py_None;
    static char *capi_kwlist[] = {"p1_in", "pp1_in", "q_in", NULL};

/*routdebugenter*/
#ifdef F2PY_REPORT_ATEXIT
    f2py_start_clock();
#endif
    if(!PyArg_ParseTupleAndKeywords(capi_args, capi_keywds, "OOO:xsec.dirac_matrices.current_init",
                                    capi_kwlist, &p1_in_capi, &pp1_in_capi, &q_in_capi))
        return NULL;
    /*frompyobj*/
    /* Processing variable p1_in */
    p1_in_Dims[0] = 4;
    capi_p1_in_intent |= F2PY_INTENT_IN;
    capi_p1_in_tmp =
        array_from_pyobj(NPY_DOUBLE, p1_in_Dims, p1_in_Rank, capi_p1_in_intent, p1_in_capi);
    if(capi_p1_in_tmp == NULL) {
        if(!PyErr_Occurred())
            PyErr_SetString(xsec_error, "failed in converting 1st argument `p1_in' of "
                                        "xsec.dirac_matrices.current_init to C/Fortran array");
    } else {
        p1_in = (double *)(PyArray_DATA(capi_p1_in_tmp));

        /* Processing variable pp1_in */
        pp1_in_Dims[0] = 4;
        capi_pp1_in_intent |= F2PY_INTENT_IN;
        capi_pp1_in_tmp =
            array_from_pyobj(NPY_DOUBLE, pp1_in_Dims, pp1_in_Rank, capi_pp1_in_intent, pp1_in_capi);
        if(capi_pp1_in_tmp == NULL) {
            if(!PyErr_Occurred())
                PyErr_SetString(xsec_error, "failed in converting 2nd argument `pp1_in' of "
                                            "xsec.dirac_matrices.current_init to C/Fortran array");
        } else {
            pp1_in = (double *)(PyArray_DATA(capi_pp1_in_tmp));

            /* Processing variable q_in */
            q_in_Dims[0] = 4;
            capi_q_in_intent |= F2PY_INTENT_IN;
            capi_q_in_tmp =
                array_from_pyobj(NPY_DOUBLE, q_in_Dims, q_in_Rank, capi_q_in_intent, q_in_capi);
            if(capi_q_in_tmp == NULL) {
                if(!PyErr_Occurred())
                    PyErr_SetString(xsec_error,
                                    "failed in converting 3rd argument `q_in' of "
                                    "xsec.dirac_matrices.current_init to C/Fortran array");
            } else {
                q_in = (double *)(PyArray_DATA(capi_q_in_tmp));

/*end of frompyobj*/
#ifdef F2PY_REPORT_ATEXIT
                f2py_start_call_clock();
#endif
                /*callfortranroutine*/
                (*f2py_func)(p1_in, pp1_in, q_in);
                if(PyErr_Occurred()) f2py_success = 0;
#ifdef F2PY_REPORT_ATEXIT
                f2py_stop_call_clock();
#endif
                /*end of callfortranroutine*/
                if(f2py_success) {
                    /*pyobjfrom*/
                    /*end of pyobjfrom*/
                    CFUNCSMESS("Building return value.\n");
                    capi_buildvalue = Py_BuildValue("");
                    /*closepyobjfrom*/
                    /*end of closepyobjfrom*/
                } /*if (f2py_success) after callfortranroutine*/
                  /*cleanupfrompyobj*/
                if((PyObject *)capi_q_in_tmp != q_in_capi) { Py_XDECREF(capi_q_in_tmp); }
            } /*if (capi_q_in_tmp == NULL) ... else of q_in*/
            /* End of cleaning variable q_in */
            if((PyObject *)capi_pp1_in_tmp != pp1_in_capi) { Py_XDECREF(capi_pp1_in_tmp); }
        } /*if (capi_pp1_in_tmp == NULL) ... else of pp1_in*/
        /* End of cleaning variable pp1_in */
        if((PyObject *)capi_p1_in_tmp != p1_in_capi) { Py_XDECREF(capi_p1_in_tmp); }
    } /*if (capi_p1_in_tmp == NULL) ... else of p1_in*/
    /* End of cleaning variable p1_in */
    /*end of cleanupfrompyobj*/
    if(capi_buildvalue == NULL) {
        /*routdebugfailure*/
    } else {
        /*routdebugleave*/
    }
    CFUNCSMESS("Freeing memory.\n");
/*freemem*/
#ifdef F2PY_REPORT_ATEXIT
    f2py_stop_clock();
#endif
    return capi_buildvalue;
}
/**************************** end of current_init ****************************/

/*********************************** det_ja ***********************************/
static char doc_f2py_rout_xsec_dirac_matrices_det_ja[] = "\
det_ja(f1v,f2v)\n\nWrapper for ``det_ja``.\
\n\nParameters\n----------\n"
                                                         "f1v : input float\n"
                                                         "f2v : input float";
/*  */
static PyObject *f2py_rout_xsec_dirac_matrices_det_ja(const PyObject *capi_self,
                                                      PyObject *capi_args, PyObject *capi_keywds,
                                                      void (*f2py_func)(double *, double *)) {
    PyObject *volatile capi_buildvalue = NULL;
    volatile int f2py_success = 1;
    /*decl*/

    double f1v = 0;
    PyObject *f1v_capi = Py_None;
    double f2v = 0;
    PyObject *f2v_capi = Py_None;
    static char *capi_kwlist[] = {"f1v", "f2v", NULL};

/*routdebugenter*/
#ifdef F2PY_REPORT_ATEXIT
    f2py_start_clock();
#endif
    if(!PyArg_ParseTupleAndKeywords(capi_args, capi_keywds, "OO:xsec.dirac_matrices.det_ja",
                                    capi_kwlist, &f1v_capi, &f2v_capi))
        return NULL;
    /*frompyobj*/
    /* Processing variable f1v */
    f2py_success = double_from_pyobj(
        &f1v, f1v_capi,
        "xsec.dirac_matrices.det_ja() 1st argument (f1v) can't be converted to double");
    if(f2py_success) {
        /* Processing variable f2v */
        f2py_success = double_from_pyobj(
            &f2v, f2v_capi,
            "xsec.dirac_matrices.det_ja() 2nd argument (f2v) can't be converted to double");
        if(f2py_success) {
/*end of frompyobj*/
#ifdef F2PY_REPORT_ATEXIT
            f2py_start_call_clock();
#endif
            /*callfortranroutine*/
            (*f2py_func)(&f1v, &f2v);
            if(PyErr_Occurred()) f2py_success = 0;
#ifdef F2PY_REPORT_ATEXIT
            f2py_stop_call_clock();
#endif
            /*end of callfortranroutine*/
            if(f2py_success) {
                /*pyobjfrom*/
                /*end of pyobjfrom*/
                CFUNCSMESS("Building return value.\n");
                capi_buildvalue = Py_BuildValue("");
                /*closepyobjfrom*/
                /*end of closepyobjfrom*/
            } /*if (f2py_success) after callfortranroutine*/
              /*cleanupfrompyobj*/
        }     /*if (f2py_success) of f2v*/
        /* End of cleaning variable f2v */
    } /*if (f2py_success) of f1v*/
    /* End of cleaning variable f1v */
    /*end of cleanupfrompyobj*/
    if(capi_buildvalue == NULL) {
        /*routdebugfailure*/
    } else {
        /*routdebugleave*/
    }
    CFUNCSMESS("Freeing memory.\n");
/*freemem*/
#ifdef F2PY_REPORT_ATEXIT
    f2py_stop_clock();
#endif
    return capi_buildvalue;
}
/******************************* end of det_ja *******************************/

/********************************* det_res1b *********************************/
static char doc_f2py_rout_xsec_dirac_matrices_det_res1b[] = "\
det_res1b(rl,rt)\n\nWrapper for ``det_res1b``.\
\n\nParameters\n----------\n"
                                                            "rl : input float\n"
                                                            "rt : input float";
/*  */
static PyObject *f2py_rout_xsec_dirac_matrices_det_res1b(const PyObject *capi_self,
                                                         PyObject *capi_args, PyObject *capi_keywds,
                                                         void (*f2py_func)(double *, double *)) {
    PyObject *volatile capi_buildvalue = NULL;
    volatile int f2py_success = 1;
    /*decl*/

    double rl = 0;
    PyObject *rl_capi = Py_None;
    double rt = 0;
    PyObject *rt_capi = Py_None;
    static char *capi_kwlist[] = {"rl", "rt", NULL};

/*routdebugenter*/
#ifdef F2PY_REPORT_ATEXIT
    f2py_start_clock();
#endif
    if(!PyArg_ParseTupleAndKeywords(capi_args, capi_keywds, "OO:xsec.dirac_matrices.det_res1b",
                                    capi_kwlist, &rl_capi, &rt_capi))
        return NULL;
    /*frompyobj*/
    /* Processing variable rl */
    f2py_success = double_from_pyobj(
        &rl, rl_capi,
        "xsec.dirac_matrices.det_res1b() 1st argument (rl) can't be converted to double");
    if(f2py_success) {
        /* Processing variable rt */
        f2py_success = double_from_pyobj(
            &rt, rt_capi,
            "xsec.dirac_matrices.det_res1b() 2nd argument (rt) can't be converted to double");
        if(f2py_success) {
/*end of frompyobj*/
#ifdef F2PY_REPORT_ATEXIT
            f2py_start_call_clock();
#endif
            /*callfortranroutine*/
            (*f2py_func)(&rl, &rt);
            if(PyErr_Occurred()) f2py_success = 0;
#ifdef F2PY_REPORT_ATEXIT
            f2py_stop_call_clock();
#endif
            /*end of callfortranroutine*/
            if(f2py_success) {
                /*pyobjfrom*/
                /*end of pyobjfrom*/
                CFUNCSMESS("Building return value.\n");
                capi_buildvalue = Py_BuildValue("");
                /*closepyobjfrom*/
                /*end of closepyobjfrom*/
            } /*if (f2py_success) after callfortranroutine*/
              /*cleanupfrompyobj*/
        }     /*if (f2py_success) of rt*/
        /* End of cleaning variable rt */
    } /*if (f2py_success) of rl*/
    /* End of cleaning variable rl */
    /*end of cleanupfrompyobj*/
    if(capi_buildvalue == NULL) {
        /*routdebugfailure*/
    } else {
        /*routdebugleave*/
    }
    CFUNCSMESS("Freeing memory.\n");
/*freemem*/
#ifdef F2PY_REPORT_ATEXIT
    f2py_stop_clock();
#endif
    return capi_buildvalue;
}
/****************************** end of det_res1b ******************************/
/*eof body*/

/******************* See f2py2e/f90mod_rules.py: buildhooks *******************/

static FortranDataDef f2py_xsec_def[] = {
    {"xmp", 0, {{-1}}, NPY_DOUBLE},   {"xmn", 0, {{-1}}, NPY_DOUBLE},
    {"xm", 0, {{-1}}, NPY_DOUBLE},    {"hbarc", 0, {{-1}}, NPY_DOUBLE},
    {"g_f", 0, {{-1}}, NPY_DOUBLE},   {"pi", 0, {{-1}}, NPY_DOUBLE},
    {"c0", 0, {{-1}}, NPY_DOUBLE},    {"e", 0, {{-1}}, NPY_DOUBLE},
    {"ef", 0, {{-1}}, NPY_DOUBLE},    {"cost", 0, {{-1}}, NPY_DOUBLE},
    {"q2", 0, {{-1}}, NPY_DOUBLE},    {"p2", 0, {{-1}}, NPY_DOUBLE},
    {"pf2", 0, {{-1}}, NPY_DOUBLE},   {"sint", 0, {{-1}}, NPY_DOUBLE},
    {"sina2", 0, {{-1}}, NPY_DOUBLE}, {"wf", 0, {{-1}}, NPY_DOUBLE},
    {"wtf", 0, {{-1}}, NPY_DOUBLE},   {NULL}};

static void f2py_setup_xsec(char *xmp, char *xmn, char *xm, char *hbarc, char *g_f, char *pi,
                            char *c0, char *e, char *ef, char *cost, char *q2, char *p2, char *pf2,
                            char *sint, char *sina2, char *wf, char *wtf) {
    int i_f2py = 0;
    f2py_xsec_def[i_f2py++].data = xmp;
    f2py_xsec_def[i_f2py++].data = xmn;
    f2py_xsec_def[i_f2py++].data = xm;
    f2py_xsec_def[i_f2py++].data = hbarc;
    f2py_xsec_def[i_f2py++].data = g_f;
    f2py_xsec_def[i_f2py++].data = pi;
    f2py_xsec_def[i_f2py++].data = c0;
    f2py_xsec_def[i_f2py++].data = e;
    f2py_xsec_def[i_f2py++].data = ef;
    f2py_xsec_def[i_f2py++].data = cost;
    f2py_xsec_def[i_f2py++].data = q2;
    f2py_xsec_def[i_f2py++].data = p2;
    f2py_xsec_def[i_f2py++].data = pf2;
    f2py_xsec_def[i_f2py++].data = sint;
    f2py_xsec_def[i_f2py++].data = sina2;
    f2py_xsec_def[i_f2py++].data = wf;
    f2py_xsec_def[i_f2py++].data = wtf;
}
extern void F_FUNC(f2pyinitxsec,
                   F2PYINITXSEC)(void (*)(char *, char *, char *, char *, char *, char *, char *,
                                          char *, char *, char *, char *, char *, char *, char *,
                                          char *, char *, char *));
static void f2py_init_xsec(void) {
    F_FUNC(f2pyinitxsec, F2PYINITXSEC)(f2py_setup_xsec);
}

static FortranDataDef f2py_dirac_matrices_def[] = {
    {"dirac_matrices_in",
     -1,
     {{-1}},
     0,
     NULL,
     (void *)f2py_rout_xsec_dirac_matrices_dirac_matrices_in,
     doc_f2py_rout_xsec_dirac_matrices_dirac_matrices_in},
    {"define_spinors",
     -1,
     {{-1}},
     0,
     NULL,
     (void *)f2py_rout_xsec_dirac_matrices_define_spinors,
     doc_f2py_rout_xsec_dirac_matrices_define_spinors},
    {"current_init",
     -1,
     {{-1}},
     0,
     NULL,
     (void *)f2py_rout_xsec_dirac_matrices_current_init,
     doc_f2py_rout_xsec_dirac_matrices_current_init},
    {"det_ja",
     -1,
     {{-1}},
     0,
     NULL,
     (void *)f2py_rout_xsec_dirac_matrices_det_ja,
     doc_f2py_rout_xsec_dirac_matrices_det_ja},
    {"det_res1b",
     -1,
     {{-1}},
     0,
     NULL,
     (void *)f2py_rout_xsec_dirac_matrices_det_res1b,
     doc_f2py_rout_xsec_dirac_matrices_det_res1b},
    {NULL}};

static void f2py_setup_dirac_matrices(char *dirac_matrices_in, char *define_spinors,
                                      char *current_init, char *det_ja, char *det_res1b) {
    int i_f2py = 0;
    f2py_dirac_matrices_def[i_f2py++].data = dirac_matrices_in;
    f2py_dirac_matrices_def[i_f2py++].data = define_spinors;
    f2py_dirac_matrices_def[i_f2py++].data = current_init;
    f2py_dirac_matrices_def[i_f2py++].data = det_ja;
    f2py_dirac_matrices_def[i_f2py++].data = det_res1b;
}
extern void F_FUNC_US(f2pyinitdirac_matrices,
                      F2PYINITDIRAC_MATRICES)(void (*)(char *, char *, char *, char *, char *));
static void f2py_init_dirac_matrices(void) {
    F_FUNC_US(f2pyinitdirac_matrices, F2PYINITDIRAC_MATRICES)(f2py_setup_dirac_matrices);
}

/*need_f90modhooks*/

/************** See f2py2e/rules.py: module_rules['modulebody'] **************/

/******************* See f2py2e/common_rules.py: buildhooks *******************/

/*need_commonhooks*/

/**************************** See f2py2e/rules.py ****************************/

static FortranDataDef f2py_routine_defs[] = {{"cc1",
                                              -1,
                                              {{-1}},
                                              0,
                                              (char *)F_FUNC(cc1, CC1),
                                              (f2py_init_func)f2py_rout_xsec_cc1,
                                              doc_f2py_rout_xsec_cc1},
                                             {"sigccc",
                                              -1,
                                              {{-1}},
                                              0,
                                              (char *)F_FUNC(sigccc, SIGCCC),
                                              (f2py_init_func)f2py_rout_xsec_sigccc,
                                              doc_f2py_rout_xsec_sigccc},

                                             /*eof routine_defs*/
                                             {NULL}};

static PyMethodDef f2py_module_methods[] = {

    {NULL, NULL}};

#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef moduledef = {
    PyModuleDef_HEAD_INIT, "xsec", NULL, -1, f2py_module_methods, NULL, NULL, NULL, NULL};
#endif

#if PY_VERSION_HEX >= 0x03000000
#define RETVAL m
PyMODINIT_FUNC PyInit_xsec(void) {
#else
#define RETVAL
PyMODINIT_FUNC initxsec(void) {
#endif
    int i;
    PyObject *m, *d, *s, *tmp;
#if PY_VERSION_HEX >= 0x03000000
    m = xsec_module = PyModule_Create(&moduledef);
#else
    m = xsec_module = Py_InitModule("xsec", f2py_module_methods);
#endif
    Py_TYPE(&PyFortran_Type) = &PyType_Type;
    import_array();
    if(PyErr_Occurred()) {
        PyErr_SetString(PyExc_ImportError, "can't initialize module xsec (failed to import numpy)");
        return RETVAL;
    }
    d = PyModule_GetDict(m);
    s = PyString_FromString("$Revision: $");
    PyDict_SetItemString(d, "__version__", s);
#if PY_VERSION_HEX >= 0x03000000
    s = PyUnicode_FromString(
#else
    s = PyString_FromString(
#endif
        "This module 'xsec' is auto-generated with f2py (version:2).\nFunctions:\n"
        "  sig = cc1(xq,w,wt,xk,xp,phi,ee0,theta,ig)\n"
        "  sig = sigccc(ig)\n"
        "Fortran 90/95 modules:\n"
        "  xsec --- xmp,xmn,xm,hbarc,g_f,pi,c0,e,ef,cost,q2,p2,pf2,sint,sina2,wf,wtf"
        "  dirac_matrices --- "
        "dirac_matrices_in(),define_spinors(),current_init(),det_ja(),det_res1b()"
        ".");
    PyDict_SetItemString(d, "__doc__", s);
    xsec_error = PyErr_NewException("xsec.error", NULL, NULL);
    Py_DECREF(s);
    for(i = 0; f2py_routine_defs[i].name != NULL; i++) {
        tmp = PyFortranObject_NewAsAttr(&f2py_routine_defs[i]);
        PyDict_SetItemString(d, f2py_routine_defs[i].name, tmp);
        Py_DECREF(tmp);
    }

    /*eof initf2pywraphooks*/
    PyDict_SetItemString(d, "dirac_matrices",
                         PyFortranObject_New(f2py_dirac_matrices_def, f2py_init_dirac_matrices));
    PyDict_SetItemString(d, "xsec", PyFortranObject_New(f2py_xsec_def, f2py_init_xsec));
    /*eof initf90modhooks*/

    /*eof initcommonhooks*/

#ifdef F2PY_REPORT_ATEXIT
    if(!PyErr_Occurred()) on_exit(f2py_report_on_exit, (void *)"xsec");
#endif

    return RETVAL;
}
#ifdef __cplusplus
}
#endif
