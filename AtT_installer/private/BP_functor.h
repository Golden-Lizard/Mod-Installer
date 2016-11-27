#pragma once

#ifndef BACKUP_OBJ
#define BACKUP_OBJ

#include<Windows.h>
#include"_file_.h"

#define windows_lean_and_mean
#define old_path L".../src/extra"

template<size_t size>
class _back_up
{
	public:

	_back_up();
	_back_up const & operator()(const _file_ & _file_to_bck_up, wchar_t (&_backup_path)[]);
	void create_Path();
	void copy_File();
	void delete_Bck();
        void check_Bck();
	//needs expanding
    private:

		static std::unique_ptr<_int16> _backed_up;
		std::unique_ptr<_file_> back_up;
		std::unique_ptr<_file_> current;

		std::wstring _back_up_path;

};



#endif
