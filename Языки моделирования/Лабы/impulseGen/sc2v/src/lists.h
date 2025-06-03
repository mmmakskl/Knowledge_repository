#ifndef SC2V_LISTS_H
#define SC2V_LISTS_H

#define MAX_NAME_LENGTH 256
 
typedef struct _write_node
{
  char name[MAX_NAME_LENGTH];
  struct _write_node *next;
} WriteNode;

typedef struct _port_node
{
  char name[MAX_NAME_LENGTH];
  char tipo[MAX_NAME_LENGTH];
  int size;
  struct _port_node *next;
  int pflag;
} PortNode;

typedef struct _signal_node
{
  char name[MAX_NAME_LENGTH];
  int size;
  int arraysize;
  struct _signal_node *next;
  int sflag;
} SignalNode;

typedef struct _bind_node
{
  char nameport[MAX_NAME_LENGTH];
  char namebind[MAX_NAME_LENGTH];
  struct _bind_node *next;
} BindNode;

typedef struct _instance_node
{
  char nameinstance[MAX_NAME_LENGTH];
  char namemodulo[MAX_NAME_LENGTH];
  BindNode *bindslist;
  struct _instance_node *next;
} InstanceNode;

typedef struct _funcinput_node
{
  int lenght;
  char name[MAX_NAME_LENGTH];
  struct _funcinput_node *next;
  int sgnflag;
} FunctionInputNode;


typedef struct _function_node
{
  char name[MAX_NAME_LENGTH];
  int outputlenght;
  FunctionInputNode *list;
  struct _function_node *next;
  int sgnflag;
} FunctionNode;

typedef struct _sensibility_node
{
  char tipo[MAX_NAME_LENGTH];
  char name[MAX_NAME_LENGTH];
  struct _sensibility_node *next;
} SensibilityNode;


typedef struct _process_node
{
  char name[MAX_NAME_LENGTH];
  char tipo[MAX_NAME_LENGTH];			//comb or seq
  SensibilityNode *list;
  struct _process_node *next;
} ProcessNode;

typedef struct _enumerates_node
{
  char name[MAX_NAME_LENGTH];
  struct _enumerates_node *next;
} EnumeratesNode;

typedef struct _enumlist_node
{
  char name[MAX_NAME_LENGTH];
  int istype;
  EnumeratesNode *list;
  struct _enumlist_node *next;
} EnumListNode;


typedef struct _DefineNode
{
  char name[MAX_NAME_LENGTH];
  struct _DefineNode *next;
} DefineNode;

typedef struct _RegNode
{
  char name[MAX_NAME_LENGTH];
  char name2[MAX_NAME_LENGTH];
  struct _RegNode *next;
} RegNode;

/*Each struct has a name and a list of the registers declared inside it*/
typedef struct _StructRegNode
{
  char name[MAX_NAME_LENGTH];
  int length;
  struct _StructRegNode *next;
} StructRegNode;

typedef struct _StructNode
{
  char name[MAX_NAME_LENGTH];
  StructRegNode *list;  
  struct _StructNode *next;
} StructNode;

#endif