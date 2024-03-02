fn main() {
    println!("cargo:rustc-link-lib=static=MyLibTest");
    println!("cargo:rustc-link-search=native=libs");
}
