/*
 * Copyright (c) 2003, 2007-14 Matteo Frigo
 * Copyright (c) 2003, 2007-14 Massachusetts Institute of Technology
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

/* This file was automatically generated --- DO NOT EDIT */
/* Generated on Sat Jul 30 16:52:44 EDT 2016 */

#include "codelet-rdft.h"

#ifdef HAVE_FMA

/* Generated by: ../../../genfft/gen_hc2cdft_c.native -fma -reorder-insns -schedule-for-pipeline -simd -compact -variables 4 -pipeline-latency 8 -trivial-stores -variables 32 -no-generate-bytw -n 12 -dif -sign 1 -name hc2cbdftv_12 -include hc2cbv.h */

/*
 * This function contains 71 FP additions, 51 FP multiplications,
 * (or, 45 additions, 25 multiplications, 26 fused multiply/add),
 * 88 stack variables, 2 constants, and 24 memory accesses
 */
#include "hc2cbv.h"

static void hc2cbdftv_12(R *Rp, R *Ip, R *Rm, R *Im, const R *W, stride rs, INT mb, INT me, INT ms)
{
     DVK(KP866025403, +0.866025403784438646763723170752936183471402627);
     DVK(KP500000000, +0.500000000000000000000000000000000000000000000);
     {
	  INT m;
	  for (m = mb, W = W + ((mb - 1) * ((TWVL / VL) * 22)); m < me; m = m + VL, Rp = Rp + (VL * ms), Ip = Ip + (VL * ms), Rm = Rm - (VL * ms), Im = Im - (VL * ms), W = W + (TWVL * 22), MAKE_VOLATILE_STRIDE(48, rs)) {
	       V Tz, TT, T1, T1j, TN, TF, TP, TL, Tx, T15, TJ, T1b, T1g, T1l, T18;
	       V T12, TO, TC, TK, Tl, T16, TQ, TU, TG, T1c, TM, T1k, Ty, T19, T1a;
	       V T13, T14, T1h, T1i, TS, TR, T1m, T1n, TI, TH;
	       {
		    V T2, Tm, T7, Tp, T8, Tq, T9, Tu, T5, Tr, Tg, Tn, Tj, Ta, T3;
		    V T4, Te, Tf, Th, Ti, TV, T6, TW, Tk, TD, Tt, TB, T11, T1f, Tw;
		    V TE, TX, Tc, Ts, T10, TZ, To, Tb, Tv, T17, T1d, T1e, TY, TA, Td;
		    T2 = LD(&(Rp[0]), ms, &(Rp[0]));
		    Tm = LD(&(Rp[WS(rs, 3)]), ms, &(Rp[WS(rs, 1)]));
		    T7 = LD(&(Rm[WS(rs, 5)]), -ms, &(Rm[WS(rs, 1)]));
		    Tp = LD(&(Rm[WS(rs, 2)]), -ms, &(Rm[0]));
		    T3 = LD(&(Rp[WS(rs, 4)]), ms, &(Rp[0]));
		    T4 = LD(&(Rm[WS(rs, 3)]), -ms, &(Rm[WS(rs, 1)]));
		    Te = LD(&(Rp[WS(rs, 1)]), ms, &(Rp[WS(rs, 1)]));
		    Tf = LD(&(Rp[WS(rs, 5)]), ms, &(Rp[WS(rs, 1)]));
		    Th = LD(&(Rm[0]), -ms, &(Rm[0]));
		    Ti = LD(&(Rm[WS(rs, 4)]), -ms, &(Rm[0]));
		    T8 = VCONJ(T7);
		    Tq = VCONJ(Tp);
		    T9 = LD(&(Rp[WS(rs, 2)]), ms, &(Rp[0]));
		    Tu = VFNMSCONJ(T4, T3);
		    T5 = VFMACONJ(T4, T3);
		    Tr = VADD(Te, Tf);
		    Tg = VSUB(Te, Tf);
		    Tn = VADD(Ti, Th);
		    Tj = VSUB(Th, Ti);
		    Ta = LD(&(Rm[WS(rs, 1)]), -ms, &(Rm[WS(rs, 1)]));
		    TV = LDW(&(W[TWVL * 4]));
		    Tz = LDW(&(W[TWVL * 18]));
		    T6 = VFNMS(LDK(KP500000000), T5, T2);
		    TW = VADD(T2, T5);
		    Ts = VFNMS(LDK(KP500000000), Tr, Tq);
		    T10 = VFMACONJ(Tp, Tr);
		    TZ = VFMACONJ(Tn, Tm);
		    To = VFNMS(LDK(KP500000000), VCONJ(Tn), Tm);
		    Tk = VFMACONJ(Tj, Tg);
		    TD = VFNMSCONJ(Tj, Tg);
		    Tb = VFMACONJ(Ta, T9);
		    Tv = VFMSCONJ(Ta, T9);
		    TT = LDW(&(W[TWVL * 2]));
		    T1 = LDW(&(W[TWVL * 20]));
		    Tt = VSUB(To, Ts);
		    TB = VADD(To, Ts);
		    T11 = VSUB(TZ, T10);
		    T1f = VADD(TZ, T10);
		    Tw = VSUB(Tu, Tv);
		    TE = VADD(Tu, Tv);
		    TX = VFMACONJ(T7, Tb);
		    Tc = VFNMS(LDK(KP500000000), Tb, T8);
		    T1j = LDW(&(W[0]));
		    T17 = LDW(&(W[TWVL * 16]));
		    T1d = LDW(&(W[TWVL * 10]));
		    TN = LDW(&(W[TWVL * 6]));
		    TF = VMUL(LDK(KP866025403), VSUB(TD, TE));
		    TP = VMUL(LDK(KP866025403), VADD(TE, TD));
		    TL = VFNMS(LDK(KP866025403), Tw, Tt);
		    Tx = VFMA(LDK(KP866025403), Tw, Tt);
		    T1e = VADD(TW, TX);
		    TY = VSUB(TW, TX);
		    TA = VADD(T6, Tc);
		    Td = VSUB(T6, Tc);
		    T15 = LDW(&(W[TWVL * 14]));
		    TJ = LDW(&(W[TWVL * 8]));
		    T1b = LDW(&(W[TWVL * 12]));
		    T1g = VZMUL(T1d, VSUB(T1e, T1f));
		    T1l = VADD(T1e, T1f);
		    T18 = VZMULI(T17, VFMAI(T11, TY));
		    T12 = VZMULI(TV, VFNMSI(T11, TY));
		    TO = VADD(TA, TB);
		    TC = VSUB(TA, TB);
		    TK = VFNMS(LDK(KP866025403), Tk, Td);
		    Tl = VFMA(LDK(KP866025403), Tk, Td);
	       }
	       T16 = VZMUL(T15, VFNMSI(TP, TO));
	       TQ = VZMUL(TN, VFMAI(TP, TO));
	       TU = VZMUL(TT, VFMAI(TF, TC));
	       TG = VZMUL(Tz, VFNMSI(TF, TC));
	       T1c = VZMULI(T1b, VFNMSI(TL, TK));
	       TM = VZMULI(TJ, VFMAI(TL, TK));
	       T1k = VZMULI(T1j, VFMAI(Tx, Tl));
	       Ty = VZMULI(T1, VFNMSI(Tx, Tl));
	       T19 = VCONJ(VSUB(T16, T18));
	       T1a = VADD(T16, T18);
	       T13 = VCONJ(VSUB(TU, T12));
	       T14 = VADD(TU, T12);
	       T1h = VADD(T1c, T1g);
	       T1i = VCONJ(VSUB(T1g, T1c));
	       TS = VCONJ(VSUB(TQ, TM));
	       TR = VADD(TM, TQ);
	       T1m = VADD(T1k, T1l);
	       T1n = VCONJ(VSUB(T1l, T1k));
	       TI = VCONJ(VSUB(TG, Ty));
	       TH = VADD(Ty, TG);
	       ST(&(Rm[WS(rs, 4)]), T19, -ms, &(Rm[0]));
	       ST(&(Rp[WS(rs, 4)]), T1a, ms, &(Rp[0]));
	       ST(&(Rm[WS(rs, 1)]), T13, -ms, &(Rm[WS(rs, 1)]));
	       ST(&(Rp[WS(rs, 1)]), T14, ms, &(Rp[WS(rs, 1)]));
	       ST(&(Rp[WS(rs, 3)]), T1h, ms, &(Rp[WS(rs, 1)]));
	       ST(&(Rm[WS(rs, 3)]), T1i, -ms, &(Rm[WS(rs, 1)]));
	       ST(&(Rm[WS(rs, 2)]), TS, -ms, &(Rm[0]));
	       ST(&(Rp[WS(rs, 2)]), TR, ms, &(Rp[0]));
	       ST(&(Rp[0]), T1m, ms, &(Rp[0]));
	       ST(&(Rm[0]), T1n, -ms, &(Rm[0]));
	       ST(&(Rm[WS(rs, 5)]), TI, -ms, &(Rm[WS(rs, 1)]));
	       ST(&(Rp[WS(rs, 5)]), TH, ms, &(Rp[WS(rs, 1)]));
	  }
     }
     VLEAVE();
}

static const tw_instr twinstr[] = {
     VTW(1, 1),
     VTW(1, 2),
     VTW(1, 3),
     VTW(1, 4),
     VTW(1, 5),
     VTW(1, 6),
     VTW(1, 7),
     VTW(1, 8),
     VTW(1, 9),
     VTW(1, 10),
     VTW(1, 11),
     {TW_NEXT, VL, 0}
};

static const hc2c_desc desc = { 12, XSIMD_STRING("hc2cbdftv_12"), twinstr, &GENUS, {45, 25, 26, 0} };

void XSIMD(codelet_hc2cbdftv_12) (planner *p) {
     X(khc2c_register) (p, hc2cbdftv_12, &desc, HC2C_VIA_DFT);
}
#else				/* HAVE_FMA */

/* Generated by: ../../../genfft/gen_hc2cdft_c.native -simd -compact -variables 4 -pipeline-latency 8 -trivial-stores -variables 32 -no-generate-bytw -n 12 -dif -sign 1 -name hc2cbdftv_12 -include hc2cbv.h */

/*
 * This function contains 71 FP additions, 30 FP multiplications,
 * (or, 67 additions, 26 multiplications, 4 fused multiply/add),
 * 90 stack variables, 2 constants, and 24 memory accesses
 */
#include "hc2cbv.h"

static void hc2cbdftv_12(R *Rp, R *Ip, R *Rm, R *Im, const R *W, stride rs, INT mb, INT me, INT ms)
{
     DVK(KP866025403, +0.866025403784438646763723170752936183471402627);
     DVK(KP500000000, +0.500000000000000000000000000000000000000000000);
     {
	  INT m;
	  for (m = mb, W = W + ((mb - 1) * ((TWVL / VL) * 22)); m < me; m = m + VL, Rp = Rp + (VL * ms), Ip = Ip + (VL * ms), Rm = Rm - (VL * ms), Im = Im - (VL * ms), W = W + (TWVL * 22), MAKE_VOLATILE_STRIDE(48, rs)) {
	       V TY, TZ, Tf, TC, Tq, TG, Tm, TF, Ty, TD, T13, T1h, T2, T9, T3;
	       V T5, T6, Tc, Tb, Td, T8, T4, Ta, T7, Te, To, Tp, Tr, Tv, Ti;
	       V Ts, Tl, Tw, Tu, Tg, Th, Tj, Tk, Tt, Tx, T11, T12;
	       T2 = LD(&(Rp[0]), ms, &(Rp[0]));
	       T8 = LD(&(Rm[WS(rs, 5)]), -ms, &(Rm[WS(rs, 1)]));
	       T9 = VCONJ(T8);
	       T3 = LD(&(Rp[WS(rs, 4)]), ms, &(Rp[0]));
	       T4 = LD(&(Rm[WS(rs, 3)]), -ms, &(Rm[WS(rs, 1)]));
	       T5 = VCONJ(T4);
	       T6 = VADD(T3, T5);
	       Tc = LD(&(Rp[WS(rs, 2)]), ms, &(Rp[0]));
	       Ta = LD(&(Rm[WS(rs, 1)]), -ms, &(Rm[WS(rs, 1)]));
	       Tb = VCONJ(Ta);
	       Td = VADD(Tb, Tc);
	       TY = VADD(T2, T6);
	       TZ = VADD(T9, Td);
	       T7 = VFNMS(LDK(KP500000000), T6, T2);
	       Te = VFNMS(LDK(KP500000000), Td, T9);
	       Tf = VSUB(T7, Te);
	       TC = VADD(T7, Te);
	       To = VSUB(T3, T5);
	       Tp = VSUB(Tb, Tc);
	       Tq = VMUL(LDK(KP866025403), VSUB(To, Tp));
	       TG = VADD(To, Tp);
	       Tr = LD(&(Rp[WS(rs, 3)]), ms, &(Rp[WS(rs, 1)]));
	       Tu = LD(&(Rm[WS(rs, 2)]), -ms, &(Rm[0]));
	       Tv = VCONJ(Tu);
	       Tg = LD(&(Rm[WS(rs, 4)]), -ms, &(Rm[0]));
	       Th = LD(&(Rm[0]), -ms, &(Rm[0]));
	       Ti = VCONJ(VSUB(Tg, Th));
	       Ts = VCONJ(VADD(Tg, Th));
	       Tj = LD(&(Rp[WS(rs, 1)]), ms, &(Rp[WS(rs, 1)]));
	       Tk = LD(&(Rp[WS(rs, 5)]), ms, &(Rp[WS(rs, 1)]));
	       Tl = VSUB(Tj, Tk);
	       Tw = VADD(Tj, Tk);
	       Tm = VMUL(LDK(KP866025403), VSUB(Ti, Tl));
	       TF = VADD(Ti, Tl);
	       Tt = VFNMS(LDK(KP500000000), Ts, Tr);
	       Tx = VFNMS(LDK(KP500000000), Tw, Tv);
	       Ty = VSUB(Tt, Tx);
	       TD = VADD(Tt, Tx);
	       T11 = VADD(Tr, Ts);
	       T12 = VADD(Tv, Tw);
	       T13 = VBYI(VSUB(T11, T12));
	       T1h = VADD(T11, T12);
	       {
		    V T1n, T1i, T14, T1a, TA, T1m, TS, T18, TO, T1e, TI, TW, T1g, T1f, T10;
		    V TX, T19, Tn, Tz, T1, T1l, TQ, TR, TP, T17, TM, TN, TL, T1d, TE;
		    V TH, TB, TV, TJ, T1p, T1k, TT, T1o, TK, TU, T1j, T1b, T16, T1c, T15;
		    T1g = VADD(TY, TZ);
		    T1n = VADD(T1g, T1h);
		    T1f = LDW(&(W[TWVL * 10]));
		    T1i = VZMUL(T1f, VSUB(T1g, T1h));
		    T10 = VSUB(TY, TZ);
		    TX = LDW(&(W[TWVL * 4]));
		    T14 = VZMULI(TX, VSUB(T10, T13));
		    T19 = LDW(&(W[TWVL * 16]));
		    T1a = VZMULI(T19, VADD(T10, T13));
		    Tn = VSUB(Tf, Tm);
		    Tz = VBYI(VADD(Tq, Ty));
		    T1 = LDW(&(W[TWVL * 20]));
		    TA = VZMULI(T1, VSUB(Tn, Tz));
		    T1l = LDW(&(W[0]));
		    T1m = VZMULI(T1l, VADD(Tn, Tz));
		    TQ = VBYI(VMUL(LDK(KP866025403), VADD(TG, TF)));
		    TR = VADD(TC, TD);
		    TP = LDW(&(W[TWVL * 6]));
		    TS = VZMUL(TP, VADD(TQ, TR));
		    T17 = LDW(&(W[TWVL * 14]));
		    T18 = VZMUL(T17, VSUB(TR, TQ));
		    TM = VADD(Tf, Tm);
		    TN = VBYI(VSUB(Ty, Tq));
		    TL = LDW(&(W[TWVL * 8]));
		    TO = VZMULI(TL, VADD(TM, TN));
		    T1d = LDW(&(W[TWVL * 12]));
		    T1e = VZMULI(T1d, VSUB(TM, TN));
		    TE = VSUB(TC, TD);
		    TH = VBYI(VMUL(LDK(KP866025403), VSUB(TF, TG)));
		    TB = LDW(&(W[TWVL * 18]));
		    TI = VZMUL(TB, VSUB(TE, TH));
		    TV = LDW(&(W[TWVL * 2]));
		    TW = VZMUL(TV, VADD(TH, TE));
		    TJ = VADD(TA, TI);
		    ST(&(Rp[WS(rs, 5)]), TJ, ms, &(Rp[WS(rs, 1)]));
		    T1p = VCONJ(VSUB(T1n, T1m));
		    ST(&(Rm[0]), T1p, -ms, &(Rm[0]));
		    T1k = VCONJ(VSUB(T1i, T1e));
		    ST(&(Rm[WS(rs, 3)]), T1k, -ms, &(Rm[WS(rs, 1)]));
		    TT = VADD(TO, TS);
		    ST(&(Rp[WS(rs, 2)]), TT, ms, &(Rp[0]));
		    T1o = VADD(T1m, T1n);
		    ST(&(Rp[0]), T1o, ms, &(Rp[0]));
		    TK = VCONJ(VSUB(TI, TA));
		    ST(&(Rm[WS(rs, 5)]), TK, -ms, &(Rm[WS(rs, 1)]));
		    TU = VCONJ(VSUB(TS, TO));
		    ST(&(Rm[WS(rs, 2)]), TU, -ms, &(Rm[0]));
		    T1j = VADD(T1e, T1i);
		    ST(&(Rp[WS(rs, 3)]), T1j, ms, &(Rp[WS(rs, 1)]));
		    T1b = VCONJ(VSUB(T18, T1a));
		    ST(&(Rm[WS(rs, 4)]), T1b, -ms, &(Rm[0]));
		    T16 = VADD(TW, T14);
		    ST(&(Rp[WS(rs, 1)]), T16, ms, &(Rp[WS(rs, 1)]));
		    T1c = VADD(T18, T1a);
		    ST(&(Rp[WS(rs, 4)]), T1c, ms, &(Rp[0]));
		    T15 = VCONJ(VSUB(TW, T14));
		    ST(&(Rm[WS(rs, 1)]), T15, -ms, &(Rm[WS(rs, 1)]));
	       }
	  }
     }
     VLEAVE();
}

static const tw_instr twinstr[] = {
     VTW(1, 1),
     VTW(1, 2),
     VTW(1, 3),
     VTW(1, 4),
     VTW(1, 5),
     VTW(1, 6),
     VTW(1, 7),
     VTW(1, 8),
     VTW(1, 9),
     VTW(1, 10),
     VTW(1, 11),
     {TW_NEXT, VL, 0}
};

static const hc2c_desc desc = { 12, XSIMD_STRING("hc2cbdftv_12"), twinstr, &GENUS, {67, 26, 4, 0} };

void XSIMD(codelet_hc2cbdftv_12) (planner *p) {
     X(khc2c_register) (p, hc2cbdftv_12, &desc, HC2C_VIA_DFT);
}
#endif				/* HAVE_FMA */
