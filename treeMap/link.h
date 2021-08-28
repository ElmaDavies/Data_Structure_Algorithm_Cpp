#pragma once
#include"binNode.h"
#define IsRoot(x) (!(x).parent)
#define IsLChild(x) (!IsRoot(x) && (&(x)==(x).parent->lc))
#define IsRChild(x) (!IsRoot(x) && (&(x)==(x).parent->rc))
#define HasParent(x) (!IsRoot(x))
#define HasLChild(x) ((x).lc)
#define HasRChild(x) ((x).rc)
#define HasChild(x) (HasLChild(x) || HasRChild(x)) //至少拥有一个孩子
#define HasBothChild(x) (HasLChild(x) && HasRChild(x)) //拥有两个孩子
#define IsLeaf(x) (!HasChild(x)) //判断是否是叶子节点，叶子节点没有孩子

/*兄弟*/
#define sibling(p)  (IsChild(*(p))?(p)->parent->rc:(p)->parent->lc)

#define uncle(x) /*叔叔*/ \
(IsChild(*(x)->parent))?(x)->parent->parent->rc:(x)->parent->parent->lc)

#define FromParentTo(x)  /*来自父亲的引用*/ \
(IsRoot(x)?_root:(IsLChild(x)?(x).parent->lc:(x).parent->rc)) 
