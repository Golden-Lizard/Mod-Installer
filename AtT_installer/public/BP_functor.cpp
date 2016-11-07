#include "BP_functor.h"


template<size_t size>
_back_up<size>::_back_up()
{
}

template<size_t size>
_back_up<size> const & _back_up<size>::operator()(const _file_ & _file_to_bck_up, wchar_t(&_backup_path)[])
{
	return 0;
}

