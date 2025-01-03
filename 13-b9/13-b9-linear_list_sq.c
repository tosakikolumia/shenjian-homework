/* 2351753 �ƿ� �Ʊ��� */  
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>		//malloc/realloc����
#include <math.h>        //fabs����
#include <string.h>		//strcpy/strcmp�Ⱥ���
#include "13-b9-linear_list_sq.h"	//��ʽ����
#if defined (_MSC_VER)
#include <stdlib.h>
#elif defined (__MINGW32__)
#include <stdlib.h>
#elif defined (__linux__)
#include <unistd.h>//exit����
#endif
/* ��ʼ�����Ա� */
Status InitList(sqlist *L)
{
    L->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (L->elem == NULL)
    	exit(LOVERFLOW);
    L->length = 0;
    L->listsize = LIST_INIT_SIZE;
    return OK;
}

/* ɾ�����Ա� */
Status DestroyList(sqlist *L)
{
    /* ����ָ��������Ҫ�ͷŶ����ռ� */
#if defined (ELEMTYPE_IS_CHAR_P) || defined (ELEMTYPE_IS_STRUCT_STUDENT_P)
    int i;

    /* �����ͷŶ����ռ� */
    for(i=0; i<L->length; i++)
        free(L->elem[i]);
#endif

    /* ��δִ�� InitList��ֱ��ִ�б�����������ܳ�����Ϊָ���ʼֵδ�� */
    if (L->elem)
    	free(L->elem);
    L->length   = 0;
    L->listsize = 0;

    return OK;
}

/* ������Ա��ѳ�ʼ�������ͷſռ䣬ֻ������ݣ� */
Status ClearList(sqlist *L)
{
    /* ����ָ��������Ҫ�ͷŶ����ռ� */
#if defined (ELEMTYPE_IS_CHAR_P) || defined (ELEMTYPE_IS_STRUCT_STUDENT_P)
    int i;

    /* �����ͷŶ����ռ� */
    for(i=0; i<L->length; i++)
        free(L->elem[i]);
#endif

    L->length = 0;
    return OK;
}

/* �ж��Ƿ�Ϊ�ձ� */
Status ListEmpty(sqlist L)
{
    if (L.length == 0)
    	return TRUE;
    else
    	return FALSE;
}

/* ���ĳ��� */
int ListLength(sqlist L)
{
    return L.length;
}

/* ȡ����Ԫ�� */
Status GetElem(sqlist L, int i, ElemType *e)
{
    if (i<1 || i>L.length)  //����Ҫ��� || L.length>0
    	return ERROR;

    /* ѭ���Ƚ��������Ա� */
#if defined (ELEMTYPE_IS_CHAR_ARRAY) || defined (ELEMTYPE_IS_CHAR_P)
    strcpy(*e, L.elem[i-1]);	//�±��0��ʼ����i��ʵ����elem[i-1]��
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT)
    memcpy(e, &(L.elem[i-1]), sizeof(ElemType)); //�±��0��ʼ����i��ʵ����elem[i-1]��
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT_P)
    memcpy(*e, L.elem[i-1], sizeof(ET)); //�±��0��ʼ����i��ʵ����elem[i-1]��
#else	//int��doubleֱ�Ӹ�ֵ
    *e = L.elem[i-1];	//�±��0��ʼ����i��ʵ����elem[i-1]��
#endif

    return OK;
}

/* ���ҷ���ָ��������Ԫ�� */
int LocateElem(sqlist L, ElemType e, Status (*compare)(ElemType e1, ElemType e2))
{
    ElemType *p = L.elem;
    int       i = 1;

    while(i<=L.length && (*compare)(*p++, e)==FALSE)
        i++;
        
    return (i<=L.length) ? i : 0;	//�ҵ�����i�����򷵻�0
}
Status PriorElem(sqlist L, ElemType cur_e, ElemType* pre_e, Status(*compare)(ElemType e1, ElemType e2))
{
    ElemType* p = L.elem;
    int       i = 1;

    /* ѭ���Ƚ��������Ա� */
    while (i <= L.length && (*compare)(*p, cur_e) == FALSE) {
        i++;
        p++;
    }

    if (i == 1 || i > L.length) //�ҵ���1��Ԫ�ػ�δ�ҵ�
        return ERROR;

#if defined (ELEMTYPE_IS_CHAR_ARRAY) || defined(ELEMTYPE_IS_CHAR_P)
    strcpy(*pre_e, *--p);	//ȡǰ��Ԫ�ص�ֵ
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT)
    memcpy(pre_e, --p, sizeof(ElemType));	//ȡǰ��Ԫ�ص�ֵ
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT_P)
    memcpy(*pre_e, *--p, sizeof(ET));	//ȡǰ��Ԫ�ص�ֵ
#else	//int��doubleֱ�Ӹ�ֵ
    * pre_e = *--p;	//ȡǰ��Ԫ�ص�ֵ
#endif
    return OK;
}
Status NextElem(sqlist L, ElemType cur_e, ElemType* next_e, Status(*compare)(ElemType e1, ElemType e2))
{
    ElemType* p = L.elem;
    int       i = 1;

    /* ѭ���Ƚ��������Ա�(����βԪ��) */
    while (i < L.length && (*compare)(*p, cur_e) == FALSE) {
        i++;
        p++;
    }

    if (i >= L.length)	//δ�ҵ������һ��Ԫ��δ�Ƚϣ�
        return ERROR;

#if defined (ELEMTYPE_IS_CHAR_ARRAY) || defined (ELEMTYPE_IS_CHAR_P)
    strcpy(*next_e, *++p);	//ȡ���Ԫ�ص�ֵ
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT)
    memcpy(next_e, ++p, sizeof(ElemType));	//ȡ���Ԫ�ص�ֵ
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT_P)
    memcpy(*next_e, *++p, sizeof(ET));	//ȡ���Ԫ�ص�ֵ
#else	//int��doubleֱ�Ӹ�ֵ
    * next_e = *++p;	//ȡ���Ԫ�ص�ֵ
#endif

    return OK;
}


/* ��ָ��λ��ǰ����һ����Ԫ�� */
Status ListInsert(sqlist * L, int i, ElemType e)
{
    ElemType* p, * q; //������㷨��һ�����ʡ�ԣ�������

    if (i<1 || i>L->length + 1)   //����Χ�� 1..length+1
        return ERROR;

    /* �ռ�����������ռ� */
    if (L->length >= L->listsize) {
        ElemType* newbase;
        newbase = (ElemType*)realloc(L->elem, (L->listsize + LISTINCREMENT) * sizeof(ElemType));
        if (!newbase)
            return LOVERFLOW;

        L->elem = newbase;
        L->listsize += LISTINCREMENT;
        //L->length��ʱ����
    }

    q = &(L->elem[i - 1]);  //��i��Ԫ�أ����µĲ���λ��

    /* �����һ����length����[length-1]�С���ʼ����i��Ԫ�����κ���һ�� */
    for (p = &(L->elem[L->length - 1]); p >= q; --p)
#if defined (ELEMTYPE_IS_CHAR_ARRAY)
        strcpy(*(p + 1), *p);
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT)
        memcpy(p + 1, p, sizeof(ElemType));	//������strcpy
#else	//int��double��charָ�롢struct studentָ�붼��ֱ�Ӹ�ֵ
        * (p + 1) = *p;
#endif

    /* ������Ԫ�أ�����+1 */
#if defined (ELEMTYPE_IS_CHAR_ARRAY)
    strcpy(*q, e);
#elif defined (ELEMTYPE_IS_CHAR_P)
    /* ԭ��L->elem[i-1]��ָ���ѷ���[i]�У�Ҫ��������ռ䣬������Ԫ�أ�����+1 */
    L->elem[i - 1] = (ElemType)malloc((strlen(e) + 1) * sizeof(char));
    if (L->elem[i - 1] == NULL)
        return LOVERFLOW;

    strcpy(*q, e);
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT)
    memcpy(q, &e, sizeof(ElemType));
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT_P)
    L->elem[i - 1] = (ElemType)malloc(sizeof(ET));
    if (L->elem[i - 1] == NULL)
        return LOVERFLOW;

    memcpy(*q, e, sizeof(ET));
#else	//int��doubleֱ�Ӹ�ֵ
    * q = e;
#endif

    L->length++;

    return OK;
}

/* ɾ��ָ��λ�õ�Ԫ�أ�������ɾ��Ԫ�ص�ֵ����e�з��� */
Status ListDelete(sqlist *L, int i, ElemType *e)
{
    ElemType *p, *q; //������㷨��һ�����ʡ�ԣ�������

    if (i<1 || i>L->length) //����Χ�� 1..length
    	return ERROR;

    p = &(L->elem[i-1]); 		//ָ���i��Ԫ��

#if defined (ELEMTYPE_IS_CHAR_ARRAY) || defined (ELEMTYPE_IS_CHAR_P)
    strcpy(*e, *p); 				//ȡ��i��Ԫ�ص�ֵ����e��
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT)
    memcpy(e, p, sizeof(ElemType));	//ȡ��i��Ԫ�ص�ֵ����e��
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT_P)
    memcpy(*e, *p, sizeof(ET));		//ȡ��i��Ԫ�ص�ֵ����e��
#else	//int��doubleֱ�Ӹ�ֵ
    *e = *p; 				//ȡ��i��Ԫ�ص�ֵ����e��
#endif

    q = &(L->elem[L->length-1]);	//ָ�����һ��Ԫ�أ�Ҳ���� q = L->elem+L->length-1

#if defined (ELEMTYPE_IS_CHAR_P) || defined (ELEMTYPE_IS_STRUCT_STUDENT_P)
    free(*p);	//�ͷſռ�
#endif

    /* �ӵ�i+1���������ǰ��һ�� */
    for (++p; p<=q; ++p) {
#if defined (ELEMTYPE_IS_CHAR_ARRAY)
	strcpy(*(p-1), *p);
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT)
	memcpy((p-1), p, sizeof(ElemType));
#else	//int��double��charָ�롢struct studentָ�붼��ֱ�Ӹ�ֵ
	*(p-1) = *p;
#endif
	}

    L->length --;	//����-1
    return OK;
}

/* �������Ա� */
Status ListTraverse(sqlist L, Status (*visit)(ElemType e))
{
    extern int line_count; //��main�ж���Ĵ�ӡ���м����������㷨�޹أ�
    ElemType *p = L.elem;
    int       i = 1;

    line_count = 0;		//�������ָ���ʼֵ�����㷨�޹أ�
    while(i<=L.length && (*visit)(*p++)==TRUE)
        i++;

    if (i<=L.length)
    	return ERROR;

    printf("\n");//����ӡһ�����У�ֻ��Ϊ�˺ÿ������㷨�޹�
    return OK;
}
Status ClearList1(sqlist* L) {
    /* ����ָ��������Ҫ�ͷŶ����ռ� */
#if defined (ELEMTYPE_IS_CHAR_P) || defined (ELEMTYPE_IS_STRUCT_STUDENT_P)
    int i;

    /* �����ͷŶ����ռ� */
    for (i = 0; i < L->length; i++)
        free(L->elem[i]);
#endif
    L->length = 0;
    if (L->listsize > LIST_INIT_SIZE) {//��ԭ������Ŀռ���ڳ�ʼ����Ŀռ䣬��ָ�ԭ���Ŀռ�
        ElemType* newbase;
        newbase = (ElemType*)realloc(L->elem, (LIST_INIT_SIZE) * sizeof(ElemType));
        if (newbase == NULL) {
            printf("�ڴ����ʧ�ܣ�\n");
            return LOVERFLOW;;
        }
        L->elem = newbase;
        L->listsize = LIST_INIT_SIZE; // ���´�С
    }
    return OK;
}
/*  �㷨1������Ԫ�� */
Status ListInsert1(sqlist* L, ElemType cur_e, ElemType e, Status(*compare)(ElemType e1, ElemType e2)) {
    if (L == NULL || L->elem == NULL) {
        return ERROR; // ������Ա��Ƿ���Ч
    }
    if (L->length == 0) {//listΪ�գ��Ҳ���cur_e���޷�����
        // ������б�����
        return ERROR; // �����������ʵķ���ֵ
    }
    // �ҵ�Ԫ�� cur_e �����һ��λ��
    int pos = -1;
    for (int i = 0; i < L->length; i++) {
        if (compare(L->elem[i], cur_e) == 1) {
            pos = i; // �������һ������ cur_e ��λ��
        }
    }

    // ���û���ҵ���ȵ�Ԫ�أ�ֱ�ӷ��� ERROR
    if (pos == -1) {
        return ERROR;
    }

    // �������λ�ã������һ�� cur_e ǰ���룩
    int insert_pos = pos + 1; // �����һ�� cur_e ǰ�����λ��
    if (insert_pos < 1 || insert_pos > L->length+1) {
        return ERROR; // Խ��
    }
    ElemType* p, * q; //������㷨��һ�����ʡ�ԣ�������

    /* �ռ�����������ռ� */
    if (L->length >= L->listsize) {
        ElemType* newbase;
        newbase = (ElemType*)realloc(L->elem, (L->listsize + LISTINCREMENT) * sizeof(ElemType));
        if (!newbase)
            return LOVERFLOW;

        L->elem = newbase;
        L->listsize += LISTINCREMENT;
        //L->length��ʱ����
    }

    q = &(L->elem[insert_pos - 1]);  //��i��Ԫ�أ����µĲ���λ��

    /* �����һ����length����[length-1]�С���ʼ����i��Ԫ�����κ���һ�� */
    for (p = &(L->elem[L->length - 1]); p >= q; --p)
#if defined (ELEMTYPE_IS_CHAR_ARRAY)
        strcpy(*(p + 1), *p);
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT)
        memcpy(p + 1, p, sizeof(ElemType));	//������strcpy
#else	//int��double��charָ�롢struct studentָ�붼��ֱ�Ӹ�ֵ
        * (p + 1) = *p;
#endif

    /* ������Ԫ�أ�����+1 */
#if defined (ELEMTYPE_IS_CHAR_ARRAY)
    strcpy(*q, e);
#elif defined (ELEMTYPE_IS_CHAR_P)
    /* ԭ��L->elem[i-1]��ָ���ѷ���[i]�У�Ҫ��������ռ䣬������Ԫ�أ�����+1 */
    L->elem[insert_pos - 1] = (ElemType)malloc((strlen(e) + 1) * sizeof(char));
    if (L->elem[insert_pos - 1] == NULL)
        return LOVERFLOW;

    strcpy(*q, e);
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT)
    memcpy(q, &e, sizeof(ElemType));
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT_P)
    L->elem[insert_pos - 1] = (ElemType)malloc(sizeof(ET));
    if (L->elem[insert_pos - 1] == NULL)
        return LOVERFLOW;

    memcpy(*q, e, sizeof(ET));
#else	//int��doubleֱ�Ӹ�ֵ
    * q = e;
#endif

    L->length++;

    return OK;
}
/* �㷨2��ɾ��Ԫ�� */
Status ListDelete1(sqlist* L, ElemType cur_e, Status(*compare)(ElemType e1, ElemType e2)) {
    if (L == NULL || L->elem == NULL) {
        return ERROR; // ������Ա��Ƿ���Ч
    }

    // �ҵ�Ԫ�� e �ĵ�һ��λ��
    int pos = -1;
    for (int i = 0; i < L->length; i++) {
        if (compare(L->elem[i], cur_e) == 1) {
            pos = i; // ���µ�һ������ e ��λ��
            break;
        }
    }

    // ���û���ҵ���ȵ�Ԫ�أ�ֱ�ӷ��� ERROR
    if (pos == -1) {
        return ERROR;
    }

    // ����ɾ��λ��
    int delete_pos = pos+1; // ɾ��λ��
    ElemType* p, * q;//������㷨,һ�����ʡ��,������
    if (delete_pos < 1 || delete_pos > L->length+1) {
        return ERROR; // Խ��
    }
    p = &(L->elem[delete_pos - 1]);
    q = &(L->elem[L->length - 1]);
    //���������Ҫ�ͷſռ�,����4�ֲ���Ҫ
#if defined (ELEMTYPE_IS_CHAR_P) || defined(ELEMTYPE_IS_STRUCT_STUDENT_P)
        free(*p);//�ͷſռ�
#endif

        /*�ӵ�i+1�����,����ǰ��һ�� */
        for (++p; p <= q; ++p) {
#if defined (ELEMTYPE_IS_CHAR_ARRAY)
            strcpy(*(p - 1), *p);
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT)
            memcpy((p - 1), p, sizeof(ElemType));
#else//int��double��charָ�롢struct studentָ�붼��ֱ�Ӹ�ֵ
            * (p - 1) = *p;
#endif
        }
        L->length--;
        // ����Ƿ���Ҫ��С�ռ�
        if (L->length % 10 == LISTINCREMENT / 2 && L->length > LIST_INIT_SIZE) {
            if (L->listsize - LISTINCREMENT > L->length) {
                int newsize = L->listsize - LISTINCREMENT;
                if (newsize < LIST_INIT_SIZE) {
                    newsize = LIST_INIT_SIZE;
                }
                ElemType* newbase = (ElemType*)realloc(L->elem, newsize * sizeof(ElemType));
                if (newbase == NULL) {
                    return LOVERFLOW;; // �����ڴ����ʧ��
                }
                L->elem = newbase;
                L->listsize = newsize; // ���´�С
            }
        }
        else if (L->length == LIST_INIT_SIZE - LISTINCREMENT / 2) {
            if (L->listsize - LISTINCREMENT > L->length) {
                int newsize = L->listsize - LISTINCREMENT;
                if (newsize < LIST_INIT_SIZE) {
                    newsize = LIST_INIT_SIZE;
                }
                ElemType* newbase = (ElemType*)realloc(L->elem, newsize * sizeof(ElemType));
                if (newbase == NULL) {
                    return LOVERFLOW;; // �����ڴ����ʧ��
                }
                L->elem = newbase;
                L->listsize = newsize; // ���´�С
            }
        }
        return OK; // ɾ���ɹ�
}
/* �㷨3��ɾ�����е���cur_e��Ԫ�� */
Status ListDelete2(sqlist* L, ElemType cur_e, Status(*compare)(ElemType e1, ElemType e2)) {//ɾ�����е���cur_e��Ԫ��
    if (L == NULL || L->elem == NULL) {
        return ERROR; // ������Ա��Ƿ���Ч
    }
    int leap = 0;
    int i=0;
    // �ҵ�Ԫ�� e �ĵ�һ��λ��
    while (i < L->length) {
        // ����ҵ���ȵ�Ԫ��
        if (compare(L->elem[i], cur_e) == 1) {
            // ɾ����ǰԪ��
            leap = 1;
            // ���������Ҫ�ͷſռ�,����4�ֲ���Ҫ
#if defined (ELEMTYPE_IS_CHAR_P) || defined(ELEMTYPE_IS_STRUCT_STUDENT_P)
            ElemType* p = &L->elem[i];
            free(*p);//�ͷſռ�
#endif
            for (int j = i; j < L->length - 1; j++) {
#if defined (ELEMTYPE_IS_CHAR_ARRAY)
                strcpy(L->elem[j], L->elem[j + 1]);
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT)
                memcpy(&L->elem[j], &L->elem[j + 1], sizeof(ElemType));
#else//int��double��charָ�롢struct studentָ�붼��ֱ�Ӹ�ֵ
                L->elem[j] = L->elem[j + 1];
#endif
            
            }
            L->length--; // ���³���

            // ����Ƿ���Ҫ��С�ռ�
            if (L->length % 10 == LISTINCREMENT / 2 && L->length > LIST_INIT_SIZE) {
                if (L->listsize - LISTINCREMENT > L->length) {
                    int newsize = L->listsize - LISTINCREMENT;
                    if (newsize < LIST_INIT_SIZE) {
                        newsize = LIST_INIT_SIZE;
                    }
                    ElemType* newbase = (ElemType*)realloc(L->elem, newsize * sizeof(ElemType));
                    if (newbase == NULL) {
                        return LOVERFLOW;; // �����ڴ����ʧ��
                    }
                    L->elem = newbase;
                    L->listsize = newsize; // ���´�С
                }
            }
            else if (L->length == LIST_INIT_SIZE - LISTINCREMENT / 2) {
                if (L->listsize - LISTINCREMENT > L->length) {
                    int newsize = L->listsize - LISTINCREMENT;
                    if (newsize < LIST_INIT_SIZE) {
                        newsize = LIST_INIT_SIZE;
                    }
                    ElemType* newbase = (ElemType*)realloc(L->elem, newsize * sizeof(ElemType));
                    if (newbase == NULL) {
                        return LOVERFLOW;; // �����ڴ����ʧ��
                    }
                    L->elem = newbase;
                    L->listsize = newsize; // ���´�С
                }
            }
        
        }
        else {
            // ֻ����û��ɾ��������²��ƶ�����һ��Ԫ��
            i++;
        }
    }
    if(leap)
    return OK; // ɾ���ɹ�
    else
    return ERROR; // û���ҵ���ȵ�Ԫ��
}
#if(0)//δ���Ե�priorElem��nextElem����
/* ���ҷ���ָ��������Ԫ�ص�ǰ��Ԫ�� */
Status PriorElem(sqlist L, ElemType cur_e, ElemType* pre_e)
{
    ElemType* p = L.elem;
    int       i = 1;

    /* ѭ���Ƚ��������Ա� */
#ifdef ELEMTYPE_IS_DOUBLE
    while (i <= L.length && fabs(*p - cur_e) >= 1e-6) {
#elif defined (ELEMTYPE_IS_CHAR_ARRAY) || defined (ELEMTYPE_IS_CHAR_P)
    while (i <= L.length && strcmp(*p, cur_e)) {
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT)
    while (i <= L.length && p->num != cur_e.num) {
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT_P)
    while (i <= L.length && (*p)->num != cur_e->num) {
#else	//ȱʡ����int����
    while (i <= L.length && *p != cur_e) {
#endif
        i++;
        p++;
    }

    if (i == 1 || i > L.length) //�ҵ���1��Ԫ�ػ�δ�ҵ�
        return ERROR;

#if defined (ELEMTYPE_IS_CHAR_ARRAY) || defined(ELEMTYPE_IS_CHAR_P)
    strcpy(*pre_e, *--p);	//ȡǰ��Ԫ�ص�ֵ
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT)
    memcpy(pre_e, --p, sizeof(ElemType));	//ȡǰ��Ԫ�ص�ֵ
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT_P)
    memcpy(*pre_e, *--p, sizeof(ET));	//ȡǰ��Ԫ�ص�ֵ
#else	//int��doubleֱ�Ӹ�ֵ
    * pre_e = *--p;	//ȡǰ��Ԫ�ص�ֵ
#endif
    return OK;
    }

/* ���ҷ���ָ��������Ԫ�صĺ��Ԫ�� */
Status NextElem(sqlist L, ElemType cur_e, ElemType * next_e)
{
    ElemType* p = L.elem;
    int       i = 1;

    /* ѭ���Ƚ��������Ա�(����βԪ��) */
#ifdef ELEMTYPE_IS_DOUBLE
    while (i < L.length && fabs(*p - cur_e) >= 1e-6) {
#elif defined (ELEMTYPE_IS_CHAR_ARRAY) || defined (ELEMTYPE_IS_CHAR_P)
    while (i < L.length && strcmp(*p, cur_e)) {
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT)
    while (i < L.length && p->num != cur_e.num) {
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT_P)
    while (i < L.length && (*p)->num != cur_e->num) {
#else	//ȱʡ����int����
    while (i < L.length && *p != cur_e) {
#endif
        i++;
        p++;
    }

    if (i >= L.length)	//δ�ҵ������һ��Ԫ��δ�Ƚϣ�
        return ERROR;

#if defined (ELEMTYPE_IS_CHAR_ARRAY) || defined (ELEMTYPE_IS_CHAR_P)
    strcpy(*next_e, *++p);	//ȡ���Ԫ�ص�ֵ
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT)
    memcpy(next_e, ++p, sizeof(ElemType));	//ȡ���Ԫ�ص�ֵ
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT_P)
    memcpy(*next_e, *++p, sizeof(ET));	//ȡ���Ԫ�ص�ֵ
#else	//int��doubleֱ�Ӹ�ֵ
    * next_e = *++p;	//ȡ���Ԫ�ص�ֵ
#endif

    return OK;
    }
#endif
