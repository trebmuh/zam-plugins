/*
 * ZamNoise  Noise detection and removal plugin
 * Copyright (C) 2014  Damien Zammit <damien@zamaudio.com> 
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * For a full copy of the GNU General Public License see the doc/GPL.txt file.
 */

#ifndef ZAMNOISEUI_HPP_INCLUDED
#define ZAMNOISEUI_HPP_INCLUDED

#include "DistrhoUI.hpp"

#include "Image.hpp"
#include "ImageWidgets.hpp"
#include "../../widgets/ZamWidgets.hpp"
#include "ZamNoisePlugin.hpp"

using DGL::Image;
using DGL::ImageButton;
using DGL::ZamKnob;

START_NAMESPACE_DISTRHO

// -----------------------------------------------------------------------

class ZamNoiseUI : public UI,
                public ZamKnob::Callback,
		public ImageButton::Callback
{
public:
    ZamNoiseUI();
    ~ZamNoiseUI() override;

protected:
    // -------------------------------------------------------------------
    // DSP Callbacks

    void parameterChanged(uint32_t index, float value) override;
    void programLoaded(uint32_t index) override;

    // -------------------------------------------------------------------
    // Widget Callbacks

    void imageKnobDragStarted(ZamKnob* knob) override;
    void imageKnobDragFinished(ZamKnob* knob) override;
    void imageKnobValueChanged(ZamKnob* knob, float value) override;
    void imageButtonClicked(ImageButton* imageButton, int button) override;

    void onDisplay() override;

private:
    Image fImgBackground;
    ScopedPointer<ImageButton> fToggleNoise;
    ScopedPointer<ZamKnob> fKnobReduction;
};

// -----------------------------------------------------------------------

END_NAMESPACE_DISTRHO

#endif // ZAMNOISEUI_HPP_INCLUDED
