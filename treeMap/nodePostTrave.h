#pragma once
template <typename T>
void BinNode<T>::travePost(BinNode<T>* x)
{
	if (!x)
	{
		return;
	}
	travePost(x->lc);
	travePost(x->rc);
	std::cout << x->data<<"::";
}