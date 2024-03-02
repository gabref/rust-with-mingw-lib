use std::ffi::c_char;

use num_derive::ToPrimitive;

#[allow(dead_code)]
#[derive(ToPrimitive)]
pub enum ProvPrinterInterfaces {
    UsbInterface = 1,
    Rs232Interface = 2,
    TCPIPInterface = 3,
}

#[repr(C)]
#[derive(Debug, Default, Copy, Clone)]
pub struct ProvPrinterStatus {
    drawer_open_close_signal: bool,
    pub printer_status_offline: bool,
    printer_cover_open: bool,
    paper_being_fed_by_button: bool,
    printing_being_stopped: bool,
    auto_cutter_error_occurred: bool,
    pub unrecoverable_error_occurred: bool,
    auto_recoverable_error_occurred: bool,
    pub sensor_paper_near_end: bool,
    sensor_paper_not_present: bool,
}

#[repr(C)]
#[derive(Debug, Default, Copy, Clone)]
pub struct ProvPrinterCustomStatus {
    open_cover: bool,
    pub out_of_paper: bool,
    cutter_error: bool,
    cash_drawer: bool,
    print_head_over_temperature: bool,
    error_has_occurred: bool,
}

#[repr(C)]
#[derive(Debug, Copy, Clone)]
pub struct ProvPrinterTextFormat {
    pub alignment: ProvPrinterAlignment,
    pub line_space: ProvPrinterLineSpace,
    pub bold: bool,
    pub underline: bool,
    pub font_type: ProvPrinterFontType,
    pub font_size: i32,
    pub font_path: *mut c_char,
}

#[allow(dead_code)]
#[repr(C)]
#[derive(Debug, Copy, Clone)]
pub enum ProvPrinterAlignment {
    AlignmentLeft,
    AlignmentRight,
    AlignmentCenter,
}

#[allow(dead_code)]
#[repr(C)]
#[derive(Debug, Copy, Clone)]
pub enum ProvPrinterFontType {
    FontTypeA,
    FontTypeB,
}

#[allow(dead_code)]
#[repr(C)]
#[derive(Debug, Copy, Clone)]
pub enum ProvPrinterFontSize {
    FontSize1,
    FontSize2,
    FontSize3,
    FontSize4,
    FontSize5,
    FontSize6,
    FontSize7,
    FontSize8,
}

#[allow(dead_code)]
#[repr(C)]
#[derive(Debug, Copy, Clone)]
pub enum ProvPrinterLineSpace {
    LineSpace0,
    LineSpace1,
    LineSpace2,
    LineSpace3,
    LineSpace4,
}
