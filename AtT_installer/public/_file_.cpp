#include "_file_.h"


_file_::_file_(const std::wstring & L_new_path, const std::wstring & L_name, const std::wstring smth, bool b_IS_REPLACEMENT):
	new_path(new std::wstring(L_new_path)),
	new_name(new std::wstring(L_name)),
	b_IsReplacement(b_IS_REPLACEMENT)
{
	++*u16_counter;

}

_file_::~_file_()
{
	delete old_path;
	delete new_path;
	delete old_name;
	delete new_name;
}

_file_::_file_(const _file_ & _ffile)
{
	*this->old_path = *_ffile.old_path;
	*this->new_path = *_ffile.new_path;
	*this->old_name = *_ffile.old_name;
	*this->new_name = *_ffile.new_name;
}

_file_::_file_(_file_ && _ffile)
{
      *this->old_path=std::move(*_ffile.old_path);
	  delete _ffile.old_path;
}

const _file_ * _file_::operator=(const _file_ & _ffile)
{
	*this->old_path = *_ffile.old_path;
	*this->new_path = *_ffile.new_path;
    *this->old_name = *_ffile.old_name;
	*this->new_name = *_ffile.new_name;

	this->b_IsReplacement = _ffile.b_IsReplacement;

	return this;
}

const _file_ * _file_::operator=(_file_ && _ffile)
{
	*this->old_path = std::move(*_ffile.old_path);
	delete _ffile.old_path;
	return this;
}

void _file_::construct_path()
{
	/*constructs a path for the new address of the file*/
	*this->new_path += path_new;

}

std::wstring _file_::select_item(wchar_t * file_name)
{
	/*returns a string with the address of the current file*/
	return *this->old_path += path_installer+*file_name;
}

void _file_::Move_File()
{
}

void _file_::construct_path(wchar_t * extra)
{
	/*extra string contains additional folders inside the parent directory*/
	*this->new_path += path_new+*extra;
}
