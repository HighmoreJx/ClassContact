/***************************************************************************
 *   Copyright (C) 2012-2015 Highway-9 Studio.                             *
 *   787280310@qq.com									                   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   CUIT Highway-9 Studio, China.									       *
 ***************************************************************************/

/*!
* \file   TR.h
* \author chengxuan   787280310@qq.com
* \date   2015-01-22
* \brief  ת���ļ���
* \version 3.0.0
*
* \verbatim
* ��ʷ
*          3.0.0   ����,
*          2015-01-22    by chengxuan
*
* \endverbatim
*
*/

#ifndef TR_H
#define TR_H

/*! \def TR_VERSION
*  �汾���ƺ꣬��Ӧv3.0.0�汾.
*/
#define TR_VERSION   0x030000

#include <QTextCodec>
#include <QString>
#include <QByteArray>

/*! ���ַ���ת����GBK����
*  \param chars ��ת����ַ���
*  \return ����ת��������ַ���
*/
inline static QString TR(const char *chars)
{
	static QTextCodec *codec = QTextCodec::codecForName("GBK");
	return codec->toUnicode(chars);
}

/*! ���غ��������ַ���ת����GBK����
*  \param chars ��ת����ַ���
*  \return ����ת��������ַ���
*/
inline static QString TR(const QByteArray &chars)
{
	static QTextCodec *codec = QTextCodec::codecForName("GBK");
	return codec->toUnicode(chars);
}

//��ȫ�ֱ�������¼��ǰ�ͻ�����Ϣ���Լ��ٶ����ݿ����
extern int gclientNo;
extern QString gclientName;
extern QString gclassName;
extern QString gadmission;
extern QString gQQ;
extern QString gmanageClassName;

#endif //TR_H
