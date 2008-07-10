//
// Utility.cpp
//
// $Id: //poco/Main/WebWidgets/ExtJS/src/Utility.cpp#17 $
//
// Library: ExtJS
// Package: Core
// Module:  Utility
//
// Copyright (c) 2007, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#include "Poco/WebWidgets/ExtJS/Utility.h"
#include "Poco/WebWidgets/ExtJS/LabelRenderer.h"
#include "Poco/WebWidgets/ExtJS/PageRenderer.h"
#include "Poco/WebWidgets/ExtJS/ButtonCellRenderer.h"
#include "Poco/WebWidgets/ExtJS/SubmitButtonCellRenderer.h"
#include "Poco/WebWidgets/ExtJS/CollapsibleRenderer.h"
#include "Poco/WebWidgets/ExtJS/FormRenderer.h"
#include "Poco/WebWidgets/ExtJS/FrameRenderer.h"
#include "Poco/WebWidgets/ExtJS/TextFieldCellRenderer.h"
#include "Poco/WebWidgets/ExtJS/TimeFieldCellRenderer.h"
#include "Poco/WebWidgets/ExtJS/DateFieldCellRenderer.h"
#include "Poco/WebWidgets/ExtJS/PasswordFieldCellRenderer.h"
#include "Poco/WebWidgets/ExtJS/NumberFieldCellRenderer.h"
#include "Poco/WebWidgets/ExtJS/ComboBoxCellRenderer.h"
#include "Poco/WebWidgets/ExtJS/ImageButtonCellRenderer.h"
#include "Poco/WebWidgets/ExtJS/TextEditCellRenderer.h"
#include "Poco/WebWidgets/ExtJS/CheckButtonCellRenderer.h"
#include "Poco/WebWidgets/ExtJS/RadioButtonCellRenderer.h"
#include "Poco/WebWidgets/ExtJS/GridLayoutRenderer.h"
#include "Poco/WebWidgets/ExtJS/PanelRenderer.h"
#include "Poco/WebWidgets/ExtJS/HorizontalLayoutRenderer.h"
#include "Poco/WebWidgets/ExtJS/VerticalLayoutRenderer.h"
#include "Poco/WebWidgets/ExtJS/ImageRenderer.h"
#include "Poco/WebWidgets/ExtJS/TabViewRenderer.h"
#include "Poco/WebWidgets/ExtJS/ListBoxCellRenderer.h"
#include "Poco/WebWidgets/ExtJS/TableRenderer.h"
#include "Poco/WebWidgets/ExtJS/ProgressIndicatorRenderer.h"

#include "Poco/WebWidgets/Label.h"
#include "Poco/WebWidgets/Page.h"
#include "Poco/WebWidgets/ButtonCell.h"
#include "Poco/WebWidgets/SubmitButtonCell.h"
#include "Poco/WebWidgets/Collapsible.h"
#include "Poco/WebWidgets/Form.h"
#include "Poco/WebWidgets/Frame.h"
#include "Poco/WebWidgets/Panel.h"
#include "Poco/WebWidgets/Cell.h"
#include "Poco/WebWidgets/View.h"
#include "Poco/WebWidgets/GridLayout.h"
#include "Poco/WebWidgets/TextFieldCell.h"
#include "Poco/WebWidgets/TimeFieldCell.h"
#include "Poco/WebWidgets/DateFieldCell.h"
#include "Poco/WebWidgets/PasswordFieldCell.h"
#include "Poco/WebWidgets/NumberFieldCell.h"
#include "Poco/WebWidgets/ComboBoxCell.h"
#include "Poco/WebWidgets/ImageButtonCell.h"
#include "Poco/WebWidgets/TextEditCell.h"
#include "Poco/WebWidgets/CheckButtonCell.h"
#include "Poco/WebWidgets/RadioButtonCell.h"
#include "Poco/WebWidgets/HorizontalLayout.h"
#include "Poco/WebWidgets/VerticalLayout.h"
#include "Poco/WebWidgets/Image.h"
#include "Poco/WebWidgets/TabView.h"
#include "Poco/WebWidgets/ListBoxCell.h"
#include "Poco/WebWidgets/Table.h"
#include "Poco/WebWidgets/WebApplication.h"
#include "Poco/WebWidgets/RequestHandler.h"
#include "Poco/WebWidgets/ProgressIndicator.h"

#include "Poco/String.h"
#include "Poco/StringTokenizer.h"
#include "Poco/NumberFormatter.h"
#include "Poco/DateTimeFormat.h"
#include <sstream>
#include <cctype>


namespace Poco {
namespace WebWidgets {
namespace ExtJS {


void Utility::initialize(LookAndFeel::Ptr ptr)
{
	ptr->registerRenderer(typeid(Label), new LabelRenderer());
	ptr->registerRenderer(typeid(Page), new PageRenderer());
	ptr->registerRenderer(typeid(ButtonCell), new ButtonCellRenderer());
	ptr->registerRenderer(typeid(SubmitButtonCell), new SubmitButtonCellRenderer());
	ptr->registerRenderer(typeid(Form), new FormRenderer());
	ptr->registerRenderer(typeid(Frame), new FrameRenderer());
	ptr->registerRenderer(typeid(Collapsible), new CollapsibleRenderer());
	ptr->registerRenderer(typeid(TextFieldCell), new TextFieldCellRenderer());
	ptr->registerRenderer(typeid(TimeFieldCell), new TimeFieldCellRenderer());
	ptr->registerRenderer(typeid(DateFieldCell), new DateFieldCellRenderer());
	ptr->registerRenderer(typeid(PasswordFieldCell), new PasswordFieldCellRenderer());
	ptr->registerRenderer(typeid(NumberFieldCell), new NumberFieldCellRenderer());
	ptr->registerRenderer(typeid(ComboBoxCell), new ComboBoxCellRenderer());
	ptr->registerRenderer(typeid(ImageButtonCell), new ImageButtonCellRenderer());
	ptr->registerRenderer(typeid(TextEditCell), new TextEditCellRenderer());
	ptr->registerRenderer(typeid(CheckButtonCell), new CheckButtonCellRenderer());
	ptr->registerRenderer(typeid(RadioButtonCell), new RadioButtonCellRenderer());
	ptr->registerRenderer(typeid(ListBoxCell), new ListBoxCellRenderer());
	ptr->registerRenderer(typeid(GridLayout), new GridLayoutRenderer());
	ptr->registerRenderer(typeid(Panel), new PanelRenderer());
	ptr->registerRenderer(typeid(HorizontalLayout), new HorizontalLayoutRenderer());
	ptr->registerRenderer(typeid(VerticalLayout), new VerticalLayoutRenderer());
	ptr->registerRenderer(typeid(Image), new ImageRenderer());
	ptr->registerRenderer(typeid(TabView), new TabViewRenderer());
	ptr->registerRenderer(typeid(Table), new TableRenderer());
	ptr->registerRenderer(typeid(ProgressIndicator), new ProgressIndicatorRenderer());
}


void Utility::initialize(ResourceManager::Ptr ptr, const Poco::Path& extJSDir)
{
	Poco::Path aDir(extJSDir);
	aDir.makeDirectory();
	ptr->appendJSInclude(Poco::Path(aDir, "ext-base.js"));
#ifdef _DEBUG
	ptr->appendJSInclude(Poco::Path(aDir, "ext-all-debug.js"));
#else	
	ptr->appendJSInclude(Poco::Path(aDir, "ext-all.js"));
#endif
	ptr->appendJSInclude(Poco::Path(aDir, "DDView.js"));
	ptr->appendJSInclude(Poco::Path(aDir, "Multiselect.js"));
	
	Poco::Path cssAll("resources/css/ext-all.css");
	cssAll.makeFile();
	
	ptr->appendCSSInclude(Poco::Path(aDir, cssAll));
	ptr->appendCSSInclude(Poco::Path(aDir, "Multiselect.css"));
}


const std::string& Utility::getTmpID()
{
	static const std::string tmp("tmp");
	return tmp;
}


void Utility::writeRenderableProperties(const Renderable* pRend, std::ostream& ostr)
{
	poco_assert_dbg (pRend != 0);
	ostr << "id:'" << pRend->id() << "'";
}


void Utility::writeRenderableProperties(const std::string& id, std::ostream& ostr)
{
	if (!id.empty())
		ostr << "id:'" << id << "'";
}


void Utility::writeCellProperties(const Cell* pCell, std::ostream& ostr, bool writeId)
{
	if (writeId)
		writeRenderableProperties(pCell->getOwner(), ostr);
	//don't support label for cell, keep this separate
	ostr << ",hideLabel:true";
	if (!pCell->isEnabled())
		ostr << ",disabled:true";
	
	View* pOwner = pCell->getOwner();
	if (pOwner)
	{
		if (!pOwner->getName().empty())
			ostr << ",name:'" << pOwner->getName() << "'";
		if (pOwner->getWidth() != 0)
			ostr << ",width:" << pOwner->getWidth();
		if (pOwner->getHeight() != 0)
			ostr << ",height:" << pOwner->getHeight();
		if (!pOwner->isVisible())
			ostr << ",hidden:true";	
	}
}



void Utility::writeCellProperties(const std::string& id, 
								const std::string& disabled, 
								const std::string& name, 
								const std::string& width,
								const std::string& height,
								std::ostream& ostr)
{
	
	writeRenderableProperties(id, ostr);
	//don't support label for cell, keep this separate
	if (!id.empty())
		ostr << ",";
	ostr << "hideLabel:true,";
	if (!disabled.empty())
		ostr << ",disabled:" << disabled;

	if (!name.empty())
		ostr << ",name:" << name;
	
	if (!width.empty())
		ostr << ",width:" << width;
	if (!height.empty())
		ostr << ",height:" << height;
}


std::string Utility::safe(const std::string& str)
{
	std::string safe(Poco::replace(str, "\\", "\\\\"));
	Poco::replaceInPlace(safe, "'", "\\'");
	return safe;
}


std::string Utility::convertPocoDateToPHPDate(const std::string& dateTimeFmt)
{
	if (dateTimeFmt == Poco::DateTimeFormat::ISO8601_FORMAT)
		return "c";

	std::string result;
	bool inPercent = false;
	for (int i = 0; i < dateTimeFmt.length(); ++i)
	{
		if (inPercent)
		{
			convertPocoDateToPHPDate(dateTimeFmt[i], result);
			inPercent = false;
		}
		else
		{
			if (dateTimeFmt[i] == '%')
			{
				poco_assert_dbg(!inPercent);
				inPercent = true;
			}
			else
				escapeCharForPHP(dateTimeFmt[i], result);
		}
	}
	return result;
}


void Utility::convertPocoDateToPHPDate(char in, std::string& result)
{
	//Not supported in POCO:
	//   *??->w - Numeric representation of the day of the week (1-7)
	//   *??->z - Day of the year starting with zero for jan the 1st (0 - 364/365)
	//   *??->W - ISO-8601 week number of year, weeks starting on Monday (01-53)
	//   *??->t - Number of days in the given month (28-31)
	//   *??->L - 1 for a yeap lear, 0 otherwise
	//   *??->o - ISO-8601 year number but if the ISO week number (W) belongs to the previous or next year, that year is used instead
	//   *??->g - 12-hour format of an hour without leading zeros
	//   *??->G - 24-hour format of an hour without leading zeros
	//   *??->T - Timezone abbreviation of the machine running the code, examples: EST, MDT, PDT
	//   *??->Z - Timezone offset in seconds (negative if west of UTC, positive if east)    -43200 to 50400
	//   *??->c - ISO 8601 date, should be handled in the caller must not occur here
	//   *??->U - Seconds since the Unix Epoch (January 1 1970 00:00:00 GMT) 1193432466 or -2138434463

	//   * %w->D - abbreviated weekday (Mon, Tue, ...)
	//   * %W->l - full weekday (Monday, Tuesday, ...)
	//   * %b->M - abbreviated month (Jan, Feb, ...)
	//   * %B->F - full month (January, February, ...)
	//   * %d->d - zero-padded day of month (01 .. 31)
	//   * %e->j - day of month (1 .. 31)
	//   * %m->m - zero-padded month (01 .. 12)
	//   * %n->n - month (1 .. 12)
	//   * %y->y - year without century (70)
	//   * %Y->Y - year with century (1970)
	//   * %H->H - hour (00 .. 23)
	//   * %h->h - hour (00 .. 12)
	//   * %a->a - am/pm
	//   * %A->A - AM/PM
	//   * %M->i - minute (00 .. 59)
	//   * %S->s - second (00 .. 59)
	//   * %i->u - millisecond (000 .. 999)
	//   * %z->P - time zone differential in ISO 8601 format (Z or +NN.NN).
	//   * %Z->O - time zone differential in RFC format (GMT or +NNNN)
	//   * %%->% - percent sign

	//Not supported in PHP/extjs
	//   * %f - space-padded day of month ( 1 .. 31), solution: map this to zeropadded: d
	//   * %o - space-padded month ( 1 .. 12), solution: map this to zeropadded: m
	//   * %c - centisecond (0 .. 9), solution use millisecond: u
	static const char table[]={
		'\x00', '\x01', '\x02', '\x03', '\x04', '\x05', '\x06', '\x07', '\x08', '\x09', '\x0A', '\x0B', '\x0C', '\x0D', '\x0E', '\x0F',
		'\x10', '\x11', '\x12', '\x13', '\x14', '\x15', '\x16', '\x17', '\x18', '\x19', '\x1A', '\x1B', '\x1C', '\x1D', '\x1E', '\x1F',
		' ',	'!',	'"',	'#',	'$',	'%',	'&',	'\'',	'(',	')',	'*',	'+',	',',	'-',	'.',	'/',
		'0',	'1',	'2',	'3',	'4',	'5',	'6',	'7',	'8',	'9',	':',	';',	'<',	'=',	'>',	'?',
		'@',	'A',	'F',	'C',	'D',	'E',	'F',	'G',	'H',	'I',	'J',	'K',	'L',	'i',	'N',	'O',
		'P',	'Q',	'R',	's',	'T',	'U',	'V',	'l',	'X',	'Y',	'O',	'[',	'\\',	']',	'^',	'_',
		'`',	'a',	'M',	'u',	'd',	'j',	'f',	'g',	'h',	'u',	'j',	'k',	'l',	'm',	'n',	'm',
		'p',	'q',	'r',	's',	't',	'u',	'v',	'D',	'x',	'y',	'P',	'{',	'|',	'}',	'~',	'\x7F'};

	//sometimes char is signed: keep this warning
	if (in < 0 || in > 127)
	{
		result.append(1, in);
		return;
	}

	result.append(1, table[in]);
}


void Utility::escapeCharForPHP(char in, std::string& result)
{
	// lowest ascii value is 32 ' '
	static const char table[]={
		'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
		'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
		'0', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '0', '0',
		'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
		'0', '1', '0', '0', '1', '0', '1', '1', '1', '0', '0', '0', '1', '1', '1', '1',
		'1', '0', '0', '1', '1', '1', '0', '1', '0', '1', '1', '0', '0', '0', '0', '0',
		'0', '1', '0', '1', '1', '0', '0', '1', '1', '1', '1', '0', '1', '1', '1', '1',
		'0', '0', '0', '1', '1', '1', '0', '1', '0', '1', '1', '0', '0', '0', '0', '0'};

	//sometimes char is signed: keep this warning
	if (in < 0 || in > 127)
	{
		result.append(1, in);
		return;
	}
	if (table[in] == '1')
	{
		result.append(1, '\\');
	}

	result.append(1, in);
}


void Utility::convertPHPDateToPocoDate(char in, std::string& result)
{
	static const char table[]={
		'\x00', '\x01', '\x02', '\x03', '\x04', '\x05', '\x06', '\x07', '\x08', '\x09', '\x0A', '\x0B', '\x0C', '\x0D', '\x0E', '\x0F',
		'\x10', '\x11', '\x12', '\x13', '\x14', '\x15', '\x16', '\x17', '\x18', '\x19', '\x1A', '\x1B', '\x1C', '\x1D', '\x1E', '\x1F',
		' ',	'!',	'"',	'#',	'$',	'%',	'&',	'\'',	'(',	')',	'*',	'+',	',',	'-',	'.',	'/',
		'0',	'1',	'2',	'3',	'4',	'5',	'6',	'7',	'8',	'9',	':',	';',	'<',	'=',	'>',	'?',
		'@',	'A',	'B',	'C',	'D',	'E',	'F',	'G',	'H',	'I',	'J',	'K',	'L',	'M',	'N',	'O',
		'P',	'Q',	'R',	'S',	'T',	'U',	'V',	'W',	'X',	'Y',	'Z',	'[',	'\\',	']',	'^',	'_',
		'`',	'a',	'b',	'c',	'd',	'e',	'f',	'g',	'h',	'i',	'j',	'k',	'l',	'm',	'n',	'o',
		'p',	'q',	'r',	's',	't',	'u',	'v',	'w',	'x',	'y',	'z',	'{',	'|',	'}',	'~',	'\x7F'};

	//sometimes char is signed: keep this warning
	if (in < 0 || in > 127)
	{
		result.append(1, in);
		return;
	}
}


LookAndFeel::Ptr Utility::createDefault()
{
	LookAndFeel::Ptr ptr = new LookAndFeel();
	Utility::initialize(ptr);
	return ptr;
}


LookAndFeel& Utility::getDefaultRenderers()
{
	static LookAndFeel::Ptr ptr = createDefault();
	return *ptr;
}


Form::Ptr Utility::insideForm(const View* pChild)
{
	Form::Ptr ptr;

	while (pChild && !ptr)
	{
		View::Ptr ptrView = pChild->parent();
		ptr = ptrView.cast<Form>();
		pChild = ptrView;
	}

	return ptr;
}


Form::Ptr Utility::insideForm(const Cell* pChild)
{
	return Utility::insideForm(pChild->getOwner());
}


bool Utility::writeJSEvent(std::ostream& out, const std::string& eventName, const std::list<JSDelegate>& delegates)
{
	//'click' : {
	//	fn: this.onClick,
	//	scope: this,
	//	delay: 100
	//}
	if (delegates.empty())
		return false;
		
	out << "'" << eventName << "':";
		
	if (delegates.size() == 1)
		out << "{fn:" << delegates.begin()->jsCode() << "}";
	else
	{
		// rather simple way to support more than one delegate
		std::ostringstream invoke;
		int maxParams = detectMaxParamCount(delegates);
		std::string fct(createFunctionSignature(maxParams));
		out << "{fn:" << fct << "{var all={";
		// the invoke function calls all the other functions sequentially
		invoke << "invoke:" << fct <<"{";
		std::list<JSDelegate>::const_iterator it = delegates.begin();
		int cnt(0);
		for (; it != delegates.end(); ++it, ++cnt)
		{
			std::string myFctName("d");
			myFctName.append(Poco::NumberFormatter::format(cnt));
			out << myFctName << ":";
			
			std::string fctName;
			std::vector<std::string> params;
			std::string code;
			analyzeFunction(*it, fctName, params, code);
			if (fctName == "function")
			{
				// an inline definition, we must have code
				if (!code.empty())
				{
					writeFunction(out, fctName, params, code);
				}
			}
			else
			{
				if (code.empty())
				{
					// a reference to another js function
					//maybe the user defined params too -> ignore them
					out << fctName;
				}
				else
				{
					// we have code, so rename the function to function :-)
					writeFunction(out, "function", params, code);
				}
			}
			out << ","; //always write comma because invoke is written as the last method
			invoke << "this." << createFunctionSignature(myFctName, maxParams) << ";";
		}
		
		invoke << "}";
		out << invoke.str() << "};"; //closes all
		
		out << "all." << createFunctionSignature("invoke", maxParams) << ";";
		out << "}"; //closes fn
		out << "}"; //closes function
	}	

	return true;
}


bool Utility::writeJSEvent(std::ostream& out, const std::string& eventName, const std::list<JSDelegate>& delegates, const Poco::WebWidgets::JSDelegate& serverCallback, std::size_t serverCallPos)
{
	// TODO: we can optimize here a bit by avoiding the copy
	std::list<JSDelegate> dels;
	std::list<JSDelegate>::const_iterator it = delegates.begin();
	bool written = false;
	for (; it != delegates.end(); ++it, --serverCallPos)
	{
		if (serverCallPos == 0)
		{
			dels.push_back(serverCallback);
			written = true;
		}
		dels.push_back(*it);
	}
	if (!written)
		dels.push_back(serverCallback);
	return writeJSEvent(out, eventName, dels);
}


void Utility::writeFunction(std::ostream& out, const std::string& fctName, const std::vector<std::string> &params, const std::string& code)
{
	out << fctName << "(";
	std::vector<std::string>::const_iterator it = params.begin();
	for (; it != params.end(); ++it)
	{
		if (it != params.begin())
			out << ",";
		out << *it;
	}
	out << ")";
	bool openWritten = false;
	if (code.find('{') != 0)
	{
		out << "{";
		openWritten = true;
	}
	out << code;
	if (openWritten)
		out << "}";
}


std::string Utility::createURI(const std::map<std::string, std::string>& addParams, Renderable::ID id)
{
	WebApplication& app = WebApplication::instance();
	std::ostringstream uri;
	std::string theUri(app.getURI().toString());
	if (theUri.empty())
		theUri = "/";
	else if (theUri[theUri.length()-1] != '/')
		theUri.append("/");
	uri << "'" << theUri;
	uri << ";"; //mark as AJAX request
	uri << RequestHandler::KEY_ID << "=" << id;
	// add optional params
	bool commaAtEnd = false;
	std::size_t cnt(1);
	std::map<std::string, std::string>::const_iterator it = addParams.begin();
	for (; it != addParams.end(); ++it, ++cnt)
	{
		uri << "&" << Utility::safe(it->first);
		commaAtEnd = false;
		if (it->second.empty())
		{
		}
		else
		{
			if (it->second[0] == '+')
			{
				// a variable was added
				uri << "='" << 	it->second;
				if (cnt < addParams.size())
				{
					uri << "+'";
				}
				commaAtEnd = true;
			}
			else
				uri << "=" << Utility::safe(it->second);
					
		}
		 
	}
	if (!commaAtEnd)
		uri << "'";
	return uri.str();
	
}


std::string Utility::createCallbackFunctionCode(const std::string& signature, const std::map<std::string, std::string>& addParams, Renderable::ID id, bool reloadPage)
{
	static const std::string onSuccessReload("function(){window.location.reload();}");
	static const std::string onFailureReload("function(){Ext.MessageBox.alert('Status','Failed to write changes back to server.');window.location.reload();}");
	static const std::string onSuccess;
	static const std::string onFailure("function(){Ext.MessageBox.alert('Status','Failed to write changes back to server.');}");
	if (reloadPage)
		return createCallbackFunctionCode(signature, addParams, id, onSuccessReload, onFailureReload);
	return createCallbackFunctionCode(signature, addParams, id, onSuccess, onFailure);
}



std::string Utility::createCallbackFunctionCode(const std::string& signature, const std::map<std::string, std::string>& addParams, Renderable::ID id, const std::string& onSuccess, const std::string& onFailure)
{
	poco_assert_dbg (!signature.empty());
	poco_assert_dbg(signature.find("function") != std::string::npos);
	poco_assert_dbg(signature.find("{") == std::string::npos);
	std::string uri(createURI(addParams, id));
	// now add the callback code
	std::ostringstream function;
	function << signature;
	function << "{var uri=" << uri << ";";
	function << "Ext.Ajax.request({url:uri";
	if (!onSuccess.empty())
		function << ",success:" << onSuccess;
	if (!onFailure.empty())
		function << ",failure:" << onFailure;
	function << "});}";
	return function.str();
}


Poco::WebWidgets::JSDelegate Utility::createServerCallback(
								const std::string& signature, 
								const std::map<std::string, std::string>& addServerParams, 
								Renderable::ID id,
								const std::string& onSuccessJS,
								const std::string& onFailureJS)
	{
		std::string code(createCallbackFunctionCode(signature, addServerParams, id, onSuccessJS, onFailureJS));
		 return (jsDelegate(code));
		
	}

int Utility::detectMaxParamCount(const std::list<JSDelegate>& delegates)
{
	int cnt = 0;
	std::list<JSDelegate>::const_iterator it = delegates.begin();
	for (; it != delegates.end(); ++it)
	{
		//count all , between ()
		
		int tmpCnt(0);
		std::string tmp;
		std::string tmp2;
		std::vector<std::string> params;
		analyzeFunction(*it, tmp, params, tmp2);
		tmpCnt = (int)params.size();
		if (tmpCnt > cnt)
			cnt = tmpCnt;
	}
	
	return cnt;
}


void Utility::analyzeFunction(const JSDelegate& delegate, std::string& fctName, std::vector<std::string>& paramNames, std::string& code)
{
	// 3 cases:
	//	function(...){...}
	//  myname(....) {}
	// myname  //external call
	const std::string& jsCode = delegate.jsCode();
	fctName.clear();
	paramNames.clear();
	code.clear();
		
	std::string::size_type pos = jsCode.find(')');
	std::string fctHeader = jsCode.substr(0, pos);
	if (pos != std::string::npos)
	{
		++pos;
		code = jsCode.substr(pos);
		Poco::trimInPlace(code);
	}
		
	Poco::StringTokenizer tok(fctHeader, "(,", Poco::StringTokenizer::TOK_TRIM | Poco::StringTokenizer::TOK_IGNORE_EMPTY);
	if (tok.count() > 0)
	{
		
		Poco::StringTokenizer::Iterator it = tok.begin();
		fctName = *it;
		++it;
		for (; it != tok.end(); ++it)
			paramNames.push_back(*it);
	}
}



std::string Utility::createFunctionSignature(int paramCnt)
{
	static const std::string fct("function");
	return createFunctionSignature(fct, paramCnt);
}


std::string Utility::createFunctionSignature(const std::string& fctName, int paramCnt)
{
	std::string result(fctName);
	result.append("(");	
	while (paramCnt > 0)
	{
		result.append("p");
		result.append(Poco::NumberFormatter::format(paramCnt));
		--paramCnt;
		if (paramCnt > 0)
			result.append(",");
	}
	result.append(")");
	return result;
}


} } } // namespace Poco::WebWidgets::ExtJS
