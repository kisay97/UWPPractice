﻿//------------------------------------------------------------------------------
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
//------------------------------------------------------------------------------
#include "pch.h"

#if defined _DEBUG && !defined DISABLE_XAML_GENERATED_BINDING_DEBUG_OUTPUT
extern "C" __declspec(dllimport) int __stdcall IsDebuggerPresent();
#endif

#include "FlowChartCanvas.xaml.h"

void ::SBPMSearchTest03::FlowChartCanvas::InitializeComponent()
{
    if (_contentLoaded)
    {
        return;
    }
    _contentLoaded = true;
    ::Windows::Foundation::Uri^ resourceLocator = ref new ::Windows::Foundation::Uri(L"ms-appx:///FlowChartCanvas.xaml");
    ::Windows::UI::Xaml::Application::LoadComponent(this, resourceLocator, ::Windows::UI::Xaml::Controls::Primitives::ComponentResourceLocation::Application);
}

void ::SBPMSearchTest03::FlowChartCanvas::Connect(int __connectionId, ::Platform::Object^ __target)
{
    switch (__connectionId)
    {
        case 1:
            {
                this->flowchartCanvas = safe_cast<::Windows::UI::Xaml::Controls::Grid^>(__target);
                (safe_cast<::Windows::UI::Xaml::Controls::Grid^>(this->flowchartCanvas))->SizeChanged += ref new ::Windows::UI::Xaml::SizeChangedEventHandler(this, (void (::SBPMSearchTest03::FlowChartCanvas::*)
                    (::Platform::Object^, ::Windows::UI::Xaml::SizeChangedEventArgs^))&FlowChartCanvas::flowchartCanvas_SizeChanged);
            }
            break;
        case 2:
            {
                this->gridRectStyle = safe_cast<::Windows::UI::Xaml::Style^>(__target);
            }
            break;
    }
    _contentLoaded = true;
}

::Windows::UI::Xaml::Markup::IComponentConnector^ ::SBPMSearchTest03::FlowChartCanvas::GetBindingConnector(int __connectionId, ::Platform::Object^ __target)
{
    __connectionId;         // unreferenced
    __target;               // unreferenced
    return nullptr;
}


