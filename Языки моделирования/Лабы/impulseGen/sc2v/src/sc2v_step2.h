/* -----------------------------------------------------------------------------
 *
 *  SystemC to Verilog Translator v0.4
 *  Provided by Universidad Rey Juan Carlos
 *
 * -----------------------------------------------------------------------------
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Library General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#ifndef SC2V_STEP2_H
#define SC2V_STEP2_H

#include "sglib.h"
#include "lists.h"
 

/* Functions for DEFINES list*/
void ShowDefines (char *filedefines);

/* Functions for WRITES list*/
WriteNode *InsertWrite (WriteNode *list,char *name);
int IsWrite (WriteNode *list,char *name);
WriteNode *ReadWritesFile (WriteNode *list,char *name);

/* Functions for ports list*/
PortNode *InsertPort (PortNode *list,char *name, char *tipo, int size, int pflag);
void ShowPortList (PortNode *list);
void EnumeratePorts (PortNode *list);

/* Functions for signals list*/
SignalNode *InsertSignal (SignalNode *list,char *name, int size,int arraysize,int sflag);
void ShowSignalsList (SignalNode* list, WriteNode* writeslist);
int IsWire (char *name, InstanceNode * list);

/* Functions for sensitivity list*/
SensibilityNode *InsertSensibility (SensibilityNode * list, char *name, char *tipo);
void ShowSensibilityList (SensibilityNode * list);

/* Functions for process list*/
ProcessNode *InsertProcess (ProcessNode * list, char *name,SensibilityNode *SensibilityList, char *tipo);
void ShowProcessList (ProcessNode *list);
void ShowProcessCode (ProcessNode *list);

/* Functions for instances and binds list*/
InstanceNode *InsertInstance (InstanceNode *list, char *nameInstance,char *namemodulo);
BindNode *InsertBind (BindNode *list, char *namePort, char *namebind);
void ShowInstancedModules (InstanceNode * list);

/* Functions for enumerates list*/
EnumeratesNode *InsertEnumerates (EnumeratesNode * list, char *name);
int ShowEnumeratesList (EnumeratesNode * list);

/*Functions of list of enumerates list*/
EnumListNode *InsertEnumList (EnumListNode * list, EnumeratesNode * enumlist,char *name, int istype);
void ShowEnumListList (EnumListNode * list);
int findEnumList (EnumListNode * list, char *name);
int findEnumerateLength (EnumListNode * list, int offset);

/* Functions for functions inputs list*/
FunctionInputNode *InsertFunctionInput (FunctionInputNode * list, char *name, int lenght, int flag);
void ShowFunctionInputs (FunctionInputNode * list);

/* Functions for functions list*/
FunctionNode *InsertFunction (FunctionNode *list, char *name,FunctionInputNode *InputsList,int outputlenght,int flag);
void ShowFunctionCode (FunctionNode *list);

#endif