#include "BP_functor.h"

template<size_t size>
_back_up<size_t size>::_back_up()
{
}

template<size_t size>
_back_up<size_t size> const & _back_up<size_t size>::operator()(const _file_ & _file_to_bck_up, wchar_t(&_backup_path)[size])
{
	/*TO DO
	*copy file to backup folder
	*rename extension to .bak
	*remove original file
	*/
    return 0;
};
