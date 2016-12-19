//
// FlowChartCanvas.xaml.h
// FlowChartCanvas Ŭ������ �����Դϴ�.
//

#pragma once

#include "FlowChartCanvas.g.h"

namespace SBPMSearchTest03
{
	/// <summary>
	/// ��ü������ ����ϰų� ������ ������ Ž���� �� �ִ� �� �������Դϴ�.
	/// </summary>
	public ref class FlowChartCanvas sealed
	{
	private:
		int nowRowNum;
		int nowColNum;
		int rowHeight;
		int colWidth;

	public:
		FlowChartCanvas();

	private:
		void FlowchartCanvasInit(int width, int height, int rowNum, int columnNum);
		void rowAppend();
		void columnAppend();

		void flowchartCanvas_SizeChanged(Platform::Object^ sender, Windows::UI::Xaml::SizeChangedEventArgs^ e);
	};
}
