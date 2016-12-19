//
// FlowChartCanvas.xaml.h
// FlowChartCanvas 클래스의 선언입니다.
//

#pragma once

#include "FlowChartCanvas.g.h"

namespace SBPMSearchTest03
{
	/// <summary>
	/// 자체적으로 사용하거나 프레임 내에서 탐색할 수 있는 빈 페이지입니다.
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
