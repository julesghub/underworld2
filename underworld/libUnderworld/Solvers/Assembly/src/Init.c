/*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
**                                                                                  **
** This file forms part of the Underworld geophysics modelling application.         **
**                                                                                  **
** For full license and copyright information, please refer to the LICENSE.md file  **
** located at the project root, or contact the authors.                             **
**                                                                                  **
**~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*/
#include <mpi.h>
#include <StGermain/libStGermain/src/StGermain.h>
#include <StgDomain/libStgDomain/src/StgDomain.h>
#include <StgFEM/libStgFEM/src/StgFEM.h>
#include <PICellerator/libPICellerator/src/PICellerator.h>
#include <Underworld/libUnderworld/src/Underworld.h>

#include "Assembly.h"

#include <stdio.h>

Bool Solvers_Assembly_Init( int* argc, char** argv[] ) {
   Stg_ComponentRegister* componentRegister = Stg_ComponentRegister_Get_ComponentRegister();


   Journal_Printf( Journal_Register( DebugStream_Type, (Name)"Context" ), "In: %s\n", __func__ );
   
   Stg_ComponentRegister_Add( componentRegister, Matrix_NaiNbj_Type, (Name)"0", _Matrix_NaiNbj_DefaultNew  );
   RegisterParent( Matrix_NaiNbj_Type, StiffnessMatrixTerm_Type );

   Stg_ComponentRegister_Add( componentRegister, ViscousPenaltyConstMatrixCartesian_Type, (Name)"0", _ViscousPenaltyConstMatrixCartesian_DefaultNew  );
   RegisterParent( ViscousPenaltyConstMatrixCartesian_Type,   ConstitutiveMatrix_Type );

   return True;
}
