#pragma once
template<typename T>
void BinNode<T>::travIn(BinNode<T>* x)
{
	if (!x)
	{
		return;
	}
	travIn(x->lc);
	std::cout << x->data<<":::";
	travIn(x->rc);
}