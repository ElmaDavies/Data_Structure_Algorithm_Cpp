#pragma once
#include"binNode.h"
#define IsRoot(x) (!(x).parent)
#define IsLChild(x) (!IsRoot(x) && (&(x)==(x).parent->lc))
#define IsRChild(x) (!IsRoot(x) && (&(x)==(x).parent->rc))
#define HasParent(x) (!IsRoot(x))
#define HasLChild(x) ((x).lc)
#define HasRChild(x) ((x).rc)
#define HasChild(x) (HasLChild(x) || HasRChild(x)) //����ӵ��һ������
#define HasBothChild(x) (HasLChild(x) && HasRChild(x)) //ӵ����������
#define IsLeaf(x) (!HasChild(x)) //�ж��Ƿ���Ҷ�ӽڵ㣬Ҷ�ӽڵ�û�к���

/*�ֵ�*/
#define sibling(p)  (IsChild(*(p))?(p)->parent->rc:(p)->parent->lc)

#define uncle(x) /*����*/ \
(IsChild(*(x)->parent))?(x)->parent->parent->rc:(x)->parent->parent->lc)

#define FromParentTo(x)  /*���Ը��׵�����*/ \
(IsRoot(x)?_root:(IsLChild(x)?(x).parent->lc:(x).parent->rc)) 
