#pragma once
template<typename T>
void BinNode<T>::travePre(BinNode<T>*x)
{
	if (!x)
	{
		return;
	}
	std::cout << x->data << ":-";;
	travePre(x->lc);
	travePre(x->rc);
}