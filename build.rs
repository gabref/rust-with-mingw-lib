fn main() {
    // link to my dummy library
    println!("cargo:rustc-link-lib=static=MyLibTest");
    println!("cargo:rustc-link-search=native=libs");

    // link to the actual library
    // println!("cargo:rustc-link-lib=static=MyLib");
    // println!("cargo:rustc-link-search=native=libs/x64");
    // println!("cargo:rustc-link-lib=static=kernel32");
    // println!("cargo:rustc-link-lib=static=user32");
    // println!("cargo:rustc-link-lib=static=gdi32");
    // println!("cargo:rustc-link-lib=static=winspool");
    // println!("cargo:rustc-link-lib=static=shell32");
    // println!("cargo:rustc-link-lib=static=ole32");
    // println!("cargo:rustc-link-lib=static=oleaut32");
    // println!("cargo:rustc-link-lib=static=uuid");
    // println!("cargo:rustc-link-lib=static=comdlg32");
    // println!("cargo:rustc-link-lib=static=advapi32");
    // println!("cargo:rustc-link-lib=static=wsock32");
    // println!("cargo:rustc-link-lib=static=setupapi");
}
