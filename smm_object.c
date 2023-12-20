//
//  smm_node.c
//  SMMarble
//
//  Created by Juyeop Kim on 2023/11/05.
//

#include "smm_common.h"
#include "smm_object.h"
#include <string.h>

#define MAX_NODETYPE    7
#define MAX_GRADE       9
#define MAX_NODE        100


static char smmNodeName[SMMNODE_TYPE_MAX][MAX_CHARNAME] = {
       "강의",
       "식당",
       "실험실",
       "집",
       "실험실로이동",
       "음식찬스",
       "축제시간"
};

char* smmObj_getTypeName(int type)
{
      return (char*)smmNodeName[type];
}


#if 0
typedef enum smmObjGrade {
    smmObjGrade_Ap = 0,
    smmObjGrade_A0,
    smmObjGrade_Am,
    smmObjGrade_Bp,
    smmObjGrade_B0,
    smmObjGrade_Bm,
    smmObjGrade_Cp,
    smmObjGrade_C0,
    smmObjGrade_Cm
} smmObjGrade_e;
#endif


smmObjGrade_e getRandomGrade(void) {
    return smmObj_getNodeGrade(smmObj_genObject("temp", smmObjType_grade, 0, 0, 0, 0));
}



//1. 구조체 형식 정의 
struct smmObject {
       char name[MAX_CHARNAME];
       smmObjType_e objType; 
       int type;
       int credit;
       int energy;
       smmObjGrade_e grade;
};





//static smmObject_t smm_node[MAX_NODE];
//static int smmObj_noNode = 0;

//3. 관련 함수 변경 
// object generation
smmObject_t *smmObj_genObject(char *name, smmObjType_e objType, int type, int credit, int energy, smmObjGrade_e grade)
{      
    smmObject_t *ptr = (smmObject_t *)malloc(sizeof(smmObject_t));

    strcpy(ptr->name, name);
    ptr->objType = objType;
    ptr->type = type;
    ptr->credit = credit;
    ptr->energy = energy;
    ptr->grade = grade;

    return ptr;
}


// member retrieving
char *smmObj_getNodeName(void *obj) {
    smmObject_t *ptr = (smmObject_t *)obj;

    return ptr->name;
}

int smmObj_getNodeType(void *obj) {
    smmObject_t *ptr = (smmObject_t *)obj;

    return ptr->type;
}

int smmObj_getNodeCredit(void *obj) {
    smmObject_t *ptr = (smmObject_t *)obj;

    return ptr->credit;
}

int smmObj_getNodeEnergy(void *obj) {
    smmObject_t *ptr = (smmObject_t *)obj;

    return ptr->energy;
}

smmObjGrade_e smmObj_getNodeGrade(void *obj) {
    smmObject_t *ptr = (smmObject_t *)obj;

    return ptr->grade;
}
