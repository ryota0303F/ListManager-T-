#pragma once
#include <vector>
//------------------------------------
// ListManager<T>�N���X
// �ϒ���Object���Ǘ����Ă���N���X
// �e���v���[�g�̓|�C���^������
//------------------------------------
template<class T>
class ListManager
{
public:
	ListManager();
	~ListManager();

	//------------------------------------
	// Object�̎擾
	// index : �擾�������v�f
	// �߂�l : �擾����Object
	// 	   �@�@ �Ȃ��ꍇ��nullptr
	//------------------------------------
	T GetObject(const unsigned int index);

	//------------------------------------
	// Object���Z�b�g
	// object : �Z�b�g������Object
	//------------------------------------
	void SetObject(const T object);

	//------------------------------------
	// Object�̑��f�[�^���̎擾
	// �߂�l : ���f�[�^��
	//------------------------------------
	unsigned int GetObjectSize();

	//------------------------------------
	// �擪�f�[�^�̎擾
	//------------------------------------
	T GetFrontObject();

	//------------------------------------
	// �����f�[�^�̎擾
	//------------------------------------
	T GetBackObject();

	//------------------------------------
	// ����f�[�^��index���擾
	// object : �擾������index��object
	// �߂�l : �v�f��index
	// 	        �Ȃ����-1
	//------------------------------------
	int SameObject(const T object);

	//------------------------------------
	// Object�̓���ւ�
	// index1 : ����ւ���v�f
	// index2 : ����ւ���v�f
	// �߂�l : �ł��Ȃ����-1
	//------------------------------------
	int ChangeObject(const unsigned int index1, const unsigned int index2);

	//------------------------------------
	// �ꕔ�f�[�^�̏����i�󂢂������͖��߂�j
	// index : �擾�������v�f
	// �߂�l : �ł��Ȃ����-1
	//------------------------------------
	int EraseDelete(const unsigned int index);

	//------------------------------------
	// �f�[�^���������Ă��̕����Ƀf�[�^�ǉ�
	// index : �v�f�̎w��
	// object : �ύX����f�[�^
	// �߂�l : �ł��Ȃ����-1
	//------------------------------------
	int EraseAndReplace(const unsigned int index, T object);

	//------------------------------------
	// ���ׂẴf�[�^�̏���
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
