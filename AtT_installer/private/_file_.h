#pragma once

#ifndef _FILE_
#define _FILE_

#include<Windows.h>
#include<sstream>
#include<string>
#include<memory>

#define windows32_lean_and_mean

#define MOVE 0x00
#define REPLACE 0x01

#define path_installer L".../SRC/FILES"
#define path_new  L"Might and Magic Heroes VII\\MMH7Game\\CookedPC"

class _file_
{
	public:

	   _file_(const std::wstring & L_new_path, const std::wstring & L_name, const std::wstring smth, bool b_IS_REPLACEMENT);//ctor,
	  ~_file_();  //dctor
	   _file_(const _file_ & _ffile);//cctor
	   _file_(_file_ && ffile);//mctor

	   const _file_ * operator=(const _file_ & _ffile); //copy op
	   const _file_ * operator=(_file_ &&      _ffile); //move op

	   void construct_path();
	   void construct_path(wchar_t * extra);
	   std::wstring select_item(wchar_t * file_name);

	   void Move_File();

	private:

		static std::unique_ptr<_int16> u16_counter;
		static std::unique_ptr<_int16> u16_replaced;

		std::wstring * old_path;
		std::wstring * new_path;
		std::wstring * old_name;
		std::wstring * new_name;

		bool b_IsReplacement;
		
};


#endif _FILE_