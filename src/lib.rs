use wrapper::{prov_connect, prov_scroll_paper};

mod defines;
mod wrapper;
mod returns;

#[no_mangle]
#[cfg(target_os = "windows")]
pub extern "stdcall" fn init() -> i32 {
    let ret = prov_connect();
    ret as i32
}
#[no_mangle]
#[cfg(target_os = "linux")]
pub extern "C" fn init() -> i32 {
    let ret = prov_connect();
    ret as i32
}

#[no_mangle]
#[cfg(target_os = "windows")]
pub extern "stdcall" fn scroll() -> i32 {
    let ret = prov_scroll_paper(5);
    ret as i32
}
#[no_mangle]
#[cfg(target_os = "linux")]
pub extern "C" fn scroll() -> i32 {
    let ret = prov_scroll_paper(5);
    ret as i32
}
