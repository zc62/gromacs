/*
 *       @(#) copyrgt.c 1.12 9/30/97
 *
 *       This source code is part of
 *
 *        G   R   O   M   A   C   S
 *
 * GROningen MAchine for Chemical Simulations
 *
 *            VERSION 2.0b
 * 
 * Copyright (c) 1990-1997,
 * BIOSON Research Institute, Dept. of Biophysical Chemistry,
 * University of Groningen, The Netherlands
 *
 * Please refer to:
 * GROMACS: A message-passing parallel molecular dynamics implementation
 * H.J.C. Berendsen, D. van der Spoel and R. van Drunen
 * Comp. Phys. Comm. 91, 43-56 (1995)
 *
 * Also check out our WWW page:
 * http://rugmd0.chem.rug.nl/~gmx
 * or e-mail to:
 * gromacs@chem.rug.nl
 *
 * And Hey:
 * Grunge ROck MAChoS
 */
typedef struct {
  /* Cut-Off stuff */
  real rshort,rlong;
  
  /* Dielectric constant resp. multiplication factor for charges */
  real zsquare,temp;
  real epsilon_r,epsfac;  
  
  /* Constants for reaction fields */
  real kappa,k_rf,c_rf;
  
  /* Constant for long range dispersion correction (average dispersion) */
  real avcsix;
      
  /* Fudge factors */
  real fudgeQQ;

  /* Lennard-Jones stuff */
  bool bLJshift;
  real rlj;
    
  /* PPPM & Shifting stuff */
  real r1,rc;
  int  ntab;
  real tabscale;
  real *VFtab;
  real *phi;
  
  /* NS Stuff */
  int  eeltype;
  int  cg0,hcg;
  int  ndelta;
  int  nWater;
  int  Dimension;
  bool bGrid,bDomDecomp;
  rvec *cg_cm;
  rvec *shift_vec;
  
  /* The actual neighbor lists !
   * The length of the neighbor list arrays, is equal to
   * the number of energy terms...
   */
  int      nn;      
  t_nblist *vdw;    
  t_nblist *coul;
  t_nblist *free;
  /* This mask array of length nn determines whether or not this bit of the
   * neighbourlists should be computed. Usually all these are true of course,
   * but not when shells are used. During minimisation all the forces that 
   * include shells are done, then after minimsation is converged the remaining
   * forces are computed.
   */
  bool     *bMask;
    
  /* Twin Range stuff. */
  bool bTwinRange;
  int  nlr;
  rvec *flr;
  rvec *fshift_lr;
  
  /* Virial Stuff */
  rvec *fshift;
  
  /* Free energy stuff */
  int     nmol;
  atom_id *mol_nr;
  real    *mol_epot;
  int     nstcalc;
  
  /* Non bonded Parameter lists */
  bool bBHAM;
  real **nbfp;
} t_forcerec;

#define C6(nbfp,ai,aj)  (nbfp)[(ai)][2*(aj)]
#define C12(nbfp,ai,aj) (nbfp)[(ai)][2*(aj)+1]

