/*
 * This file is part of the MicroPython project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2017 Scott Shawcroft for Adafruit Industries
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef COMMON_HAL_USB_HID_DEVICE_H
#define COMMON_HAL_USB_HID_DEVICE_H

#include <stdint.h>
#include <stdbool.h>

#include "py/obj.h"

#define UDI_HID_MOUSE_REPORT_SIZE 4
#define UDI_HID_KBD_REPORT_SIZE 8

enum usb_hid_device_kind {
    USB_HID_UNKNOWN,
    USB_HID_MOUSE,
    USB_HID_KEYBOARD,
};

typedef struct {
    mp_obj_base_t base;
    enum usb_hid_device_kind kind;
    uint8_t endpoint;
    uint8_t report_length;
    uint8_t* report_buffer;
    uint8_t usage_page;
    uint8_t usage;

} usb_hid_device_obj_t;

usb_hid_device_obj_t usb_hid_devices[2];
// Indices into usb_hid_devices:
#define USB_HID_DEVICE_MOUSE 0
#define USB_HID_DEVICE_KEYBOARD 1

void usb_hid_init(void);
void usb_hid_reset(void);

#endif  // COMMON_HAL_USB_HID_DEVICE_H
