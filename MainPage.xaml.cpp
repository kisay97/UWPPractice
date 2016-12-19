//
// MainPage.xaml.cpp
// MainPage 클래스의 구현입니다.
//

#include "pch.h"
#include "MainPage.xaml.h"

using namespace SBPMSearchTest03;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Shapes;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

// 빈 페이지 항목 템플릿은 http://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409 에 문서화되어 있습니다.

MainPage::MainPage()
{
	InitializeComponent();

	rowHeight = 50;
	colWidth = 50;
	nowColNum = 10;
	nowRowNum = 10;

	FlowchartCanvasInit(colWidth, rowHeight, nowRowNum, nowColNum);
}


void MainPage::FlowchartCanvasInit(int width, int height, int rowNum, int columnNum) {
	nowRowNum = rowNum;
	nowColNum = columnNum;

	for (int i = 0; i < rowNum; i++) {
		auto rowDef = ref new RowDefinition;
		rowDef->Height = height;
		flowchartCanvas->RowDefinitions->Append(rowDef);
	}
	for (int i = 0; i < columnNum; i++) {
		auto colDef = ref new ColumnDefinition;
		colDef->Width = width;
		flowchartCanvas->ColumnDefinitions->Append(colDef);
	}

	for (int i = 0; i < rowNum; i++) {
		for (int j = 0; j < columnNum; j++) {
			auto tempRect = ref new Rectangle;
			tempRect->Style = gridRectStyle;
			tempRect->Height = height;
			tempRect->Width = width;
			tempRect->SetValue(Grid::ColumnProperty, j);
			tempRect->SetValue(Grid::RowProperty, i);
			flowchartCanvas->Children->Append(tempRect);
		}
	}
}

void MainPage::rowAppend() {
	auto rowDef = ref new RowDefinition;
	rowDef->Height = rowHeight;
	flowchartCanvas->RowDefinitions->Append(rowDef);

	for (int i = 0; i < flowchartCanvas->ColumnDefinitions->Size; i++) {
		auto tempRect = ref new Rectangle;
		tempRect->Style = gridRectStyle;
		tempRect->Height = rowHeight;
		tempRect->Width = colWidth;
		tempRect->SetValue(Grid::ColumnProperty, i);
		tempRect->SetValue(Grid::RowProperty, nowRowNum);
		flowchartCanvas->Children->Append(tempRect);
	}

	nowRowNum++;
}

void MainPage::columnAppend() {
	auto colDef = ref new ColumnDefinition;
	colDef->Width = colWidth;
	flowchartCanvas->ColumnDefinitions->Append(colDef);

	for (int i = 0; i < flowchartCanvas->RowDefinitions->Size; i++) {
		auto tempRect = ref new Rectangle;
		tempRect->Style = gridRectStyle;
		tempRect->Height = rowHeight;
		tempRect->Width = colWidth;
		tempRect->SetValue(Grid::ColumnProperty, nowColNum);
		tempRect->SetValue(Grid::RowProperty, i);
		flowchartCanvas->Children->Append(tempRect);
	}

	nowColNum++;
}


void MainPage::RowAppendButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e) {
	rowAppend();
}

void MainPage::ColumnAppendButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e) {
	columnAppend();
}

void SBPMSearchTest03::MainPage::ScrollViewer_SizeChanged(Platform::Object^ sender, Windows::UI::Xaml::SizeChangedEventArgs^ e)
{
	wchar_t debugBuf[256];
	int canvasHeight = (int)(flowchartCanvas->ActualHeight);
	int canvasWidth = (int)(flowchartCanvas->ActualWidth);
	swprintf_s(debugBuf, L"canvasHeight : %lf, canvasWidth : %lf\n", flowchartCanvas->ActualHeight, flowchartCanvas->ActualWidth);
	OutputDebugString(debugBuf);

	int tempRowNum = (canvasHeight / rowHeight) + ((canvasHeight%rowHeight) ? 1 : 0);
	int tempColNum = (canvasWidth / colWidth) + ((canvasWidth%colWidth) ? 1 : 0);

	swprintf_s(debugBuf, 
		L"nowRowNum : %d, nowColNum : %d\ntempRowNum : %d, tempColNum : %d\n", 
		nowRowNum, nowColNum, tempRowNum, tempColNum);
	OutputDebugString(debugBuf);

	while (tempRowNum > nowRowNum) {
		rowAppend();
	}

	while (tempColNum > nowColNum) {
		columnAppend();
	}
}