#pragma once
#include <vector>
//------------------------------------
// ListManager<T>クラス
// 可変長でObjectを管理しているクラス
// テンプレートはポインタを入れる
//------------------------------------
template<class T>
class ListManager
{
public:
	ListManager();
	~ListManager();

	//------------------------------------
	// Objectの取得
	// index : 取得したい要素
	// 戻り値 : 取得したObject
	// 	   　　 ない場合はnullptr
	//------------------------------------
	T GetObject(const unsigned int index);

	//------------------------------------
	// Objectをセット
	// object : セットしたいObject
	//------------------------------------
	void SetObject(const T object);

	//------------------------------------
	// Objectの総データ数の取得
	// 戻り値 : 総データ数
	//------------------------------------
	unsigned int GetObjectSize();

	//------------------------------------
	// 先頭データの取得
	//------------------------------------
	T GetFrontObject();

	//------------------------------------
	// 末尾データの取得
	//------------------------------------
	T GetBackObject();

	//------------------------------------
	// 同一データのindexを取得
	// object : 取得したいindexのobject
	// 戻り値 : 要素のindex
	// 	        なければ-1
	//------------------------------------
	int SameObject(const T object);

	//------------------------------------
	// Objectの入れ替え
	// index1 : 入れ替える要素
	// index2 : 入れ替える要素
	// 戻り値 : できなければ-1
	//------------------------------------
	int ChangeObject(const unsigned int index1, const unsigned int index2);

	//------------------------------------
	// 一部データの消去（空いた部分は埋める）
	// index : 取得したい要素
	// 戻り値 : できなければ-1
	//------------------------------------
	int EraseDelete(const unsigned int index);

	//------------------------------------
	// データを消去してその部分にデータ追加
	// index : 要素の指定
	// object : 変更するデータ
	// 戻り値 : できなければ-1
	//------------------------------------
	int EraseAndReplace(const unsigned int index, T object);

	//------------------------------------
	// すべてのデータの消去
	//------------------------------------
	void AllDelete();


private:
	std::vector<T>* m_list;
};

template<class T>
inline ListManager<T>::ListManager()
{
	m_list = new std::vector<T>();
	m_list->clear();
}

template<class T>
inline ListManager<T>::~ListManager()
{
	AllDelete();
	m_list->clear();
	std::vector<T>().swap(*m_list);
	delete m_list;
}

template<class T>
inline T ListManager<T>::GetObject(const unsigned int index)
{
	if (index >= GetObjectSize())
	{
		return nullptr;
	}
	return m_list->at(index);
}

template<class T>
inline void ListManager<T>::SetObject(const T object)
{
	m_list->push_back(object);
}

template<class T>
inline unsigned int ListManager<T>::GetObjectSize()
{
	return (unsigned int)m_list->size();
}

template<class T>
inline T ListManager<T>::GetFrontObject()
{
	return m_list->front();
}

template<class T>
inline T ListManager<T>::GetBackObject()
{
	return m_list->back();
}

template<class T>
inline int ListManager<T>::SameObject(const T object)
{
	for (int i = 0; i < (int)GetObjectSize(); i++)
	{
		if (object == m_list->at(i))
		{
			return i;
		}
	}
	return -1;
}

template<class T>
inline int ListManager<T>::ChangeObject(const unsigned int index1, const unsigned int index2)
{
	if (index1 >= GetObjectSize() || index2 >= GetObjectSize())
	{
		return -1;
	}
	T data = m_list->at(index1);
	m_list->at(index1) = m_list->at(index2);
	m_list->at(index2) = data;
	return 0;
}

template<class T>
inline int ListManager<T>::EraseDelete(const unsigned int index)
{
	if (index >= GetObjectSize())
	{
		return -1;
	}
	delete m_list->at(index);
	m_list->erase(m_list->begin() + index);
	return 0;
}

template<class T>
inline int ListManager<T>::EraseAndReplace(const unsigned int index, T object)
{
	if (index >= GetObjectSize())
	{
		return -1;
	}
	delete m_list->at(index);
	m_list->at(index) = object;
	return 0;
}

template<class T>
inline void ListManager<T>::AllDelete()
{
	for (unsigned int i = 0; i < m_list->size(); i++)
	{
		delete m_list->at(i);
	}
	m_list->clear();
}
