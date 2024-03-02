use super::{
    defines::{
        ProvPrinterAlignment, ProvPrinterCustomStatus, ProvPrinterFontType, ProvPrinterInterfaces,
        ProvPrinterLineSpace, ProvPrinterStatus, ProvPrinterTextFormat,
    },
    returns::ProvRet,
};
use num_traits::{FromPrimitive, ToPrimitive};
use std::{
    ffi::{c_char, CString},
    ptr,
};

extern "C" {
    fn EL_PRINTER_Connect(connect_interface: i32, ...) -> i32;
    fn EL_PRINTER_PrintSimpleText(text: *mut c_char) -> i32;
    fn EL_PRINTER_PrintText(format: ProvPrinterTextFormat, text: *mut c_char) -> i32;
    fn EL_PRINTER_GetStatus(status: *mut ProvPrinterStatus) -> i32;
    fn EL_PRINTER_GetCustomStatus(status: *mut ProvPrinterCustomStatus) -> i32;
    fn EL_PRINTER_ScrollPaper(lines: i32) -> i32;
}

/// convert a rust string to a c string and returns the raw pointer
fn rust_string_to_c_string(rust_string: String) -> *mut c_char {
    let cstr_output = CString::new(rust_string).unwrap();
    cstr_output.into_raw()
}

pub fn prov_connect() -> ProvRet {
    let ret;
    let interface = ProvPrinterInterfaces::UsbInterface
        .to_i32()
        .unwrap_or_else(|| 1);
    unsafe {
        ret = EL_PRINTER_Connect(interface, ptr::null_mut::<c_char>(), 0);
    }
    FromPrimitive::from_i32(ret).unwrap_or_else(|| ProvRet::NotProvProduct)
}

#[allow(dead_code)]
pub fn prov_print_simple_text(text: String) -> ProvRet {
    let ret;
    let cstr_text = rust_string_to_c_string(text);
    unsafe {
        ret = EL_PRINTER_PrintSimpleText(cstr_text);
    }
    FromPrimitive::from_i32(ret).unwrap_or_else(|| ProvRet::NotProvProduct)
}

pub fn prov_print_text(text: String, text_size: i32) -> ProvRet {
    let ret;
    let cstr_text = rust_string_to_c_string(text);
    let format = ProvPrinterTextFormat {
        alignment: ProvPrinterAlignment::AlignmentLeft,
        line_space: ProvPrinterLineSpace::LineSpace1,
        bold: false,
        underline: false,
        font_type: ProvPrinterFontType::FontTypeA,
        font_size: text_size,
        font_path: ptr::null_mut::<c_char>(),
    };
    unsafe {
        ret = EL_PRINTER_PrintText(format, cstr_text);
    }
    FromPrimitive::from_i32(ret).unwrap_or_else(|| ProvRet::NotProvProduct)
}

pub fn prov_get_status(status: &mut ProvPrinterStatus) -> ProvRet {
    let ret;
    unsafe {
        // ret = EL_PRINTER_GetStatus(&mut status as *mut ProvPrinterStatus);
        ret = EL_PRINTER_GetStatus(status);
    }
    FromPrimitive::from_i32(ret).unwrap_or_else(|| ProvRet::NotProvProduct)
}

pub fn prov_get_custom_status(status: &mut ProvPrinterCustomStatus) -> ProvRet {
    let ret;
    unsafe {
        ret = EL_PRINTER_GetCustomStatus(status);
    }
    FromPrimitive::from_i32(ret).unwrap_or_else(|| ProvRet::NotProvProduct)
}

pub fn prov_scroll_paper(lines: i32) -> ProvRet {
    let ret;
    unsafe {
        ret = EL_PRINTER_ScrollPaper(lines);
    }
    FromPrimitive::from_i32(ret).unwrap_or_else(|| ProvRet::NotProvProduct)
}
