use num_derive::FromPrimitive;

#[derive(Debug, thiserror::Error, FromPrimitive)]
pub enum ProvRet {
    #[error("No errors")]
    Ok = 0,
    #[error("Functionality not identified")]
    FunctionNotFound,
    #[error("Test Failed")]
    TestFail,
    #[error("Null parameter")]
    NullParameter,
    #[error("Invalid parameter")]
    InvalidParameter,
    #[error("Timeout")]
    Timeout,
    #[error("Operation cancelled")]
    Cancelled,
    #[error("Could not allocate dynamic memory")]
    CouldNotAllocateMemory,
    #[error("Not enough space in buffer")]
    BufferNotEnought,
    #[error("Out of bounds")]
    OutOfBounds,
    #[error("Invalid connection with printer")]
    InvalidConnection,
    #[error("Usb could not be found")]
    UsbCouldNotFound = 25000,
    #[error("Usb permission denied")]
    UsbPermissionDenied,
    #[error("Usb write failed")]
    UsbWriteFailed,
    #[error("Usb read failed")]
    UsbReadFailed,
    #[error("Usb close failed")]
    UsbCloseFailed,
    #[error("RS232 could not be found")]
    RS232CouldNotFound = 26000,
    #[error("RS232 permission denied")]
    RS232PermissionDenied,
    #[error("RS232 write failed")]
    RS232WriteFailed,
    #[error("RS232 read failed")]
    RS232ReadFailed,
    #[error("RS232 close failed")]
    RS232CloseFailed,
    #[error("RS232 baudrate error")]
    RS232BaudrateError,
    #[error("TCP/IP socket error")]
    TCPIPSocketError = 27000,
    #[error("TCP/IP socket connection failed")]
    TCPIPFailedConnection,
    #[error("TCP/IP invalid connection address")]
    TCPIPInvalidAddress,
    #[error("TCP/IP send failed")]
    TCPIPSendFailed,
    #[error("TCP/IP receive failed")]
    TCPIPReceiveFailed,
    #[error("TCP/IP Stop failed")]
    TCPIPStopFailed,
    #[error("Not a Prov G250 printer")]
    NotProvProduct = 30000,
}
