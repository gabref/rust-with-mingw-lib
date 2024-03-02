/**
 * @file EasyLayer.h
 * @author Gabriel Calper Seabra gabriel.seabra@itriad.org.br
 * @author Rodrigo Jesner Silva Trindade rodrigo.trindade@itriad.org.br
 * @brief This Library is an easy interface with G250 printer to become more easy the development
 * @version 2.0.1
 * @date 14/12/2022
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef _EASYLAYER_H_


#ifdef __cplusplus
    extern "C"  {
#endif


#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>


typedef const char* String;
typedef String EL_PRINTER_HTML;
typedef const char* EL_Header;
typedef const void* EL_Row;


typedef enum
{
    USB_INTERFACE = 1,
    RS232_INTERFACE = 2,
    TCPIP_INTERFACE = 3
} EL_PRINTER_Interface;


typedef enum
{
    EL_RET_OK = 0,
    EL_RET_FUNCTION_NOT_FOUND,
    EL_RET_TEST_FAIL,
    EL_RET_NULL_PARAMETER,
    EL_RET_INVALID_PARAMETER,
    EL_RET_TIMEOUT,
    EL_RET_CANCELLED,
    EL_RET_COULD_NOT_ALLOCATE_MEMORY,
    EL_RET_BUFFER_NOT_ENOUGH,
    EL_RET_OUT_OF_BOUNDS,
    EL_RET_INVALID_CONNECTION,

    EL_RET_USB_COULD_NOT_FOUND = 25000,
    EL_RET_USB_PERMISSION_DENIED,
    EL_RET_USB_WRITE_FAILED,
    EL_RET_USB_READ_FAILED,
    EL_RET_USB_CLOSE_FAILED,

    EL_RET_RS232_COULD_NOT_FOUND = 26000,
    EL_RET_RS232_PERMISSION_DENIED,
    EL_RET_RS232_WRITE_FAILED,
    EL_RET_RS232_READ_FAILED,
    EL_RET_RS232_CLOSE_FAILED,
    EL_RET_RS232_BAUDRATE_ERROR,

    EL_RET_TCPIP_SOCKET_ERROR = 27000,
    EL_RET_TCPIP_FAILED_CONNECTION,
    EL_RET_TCPIP_INVALID_ADDRESS,
    EL_RET_TCPIP_SEND_FAILED,
    EL_RET_TCPIP_RECEIVE_FAILED,
    EL_RET_TCPIP_STOP_FAILED,

    EL_ERR_NOT_GERTEC_PRODUCT = 30000
} EL_e_Ret;


typedef struct EL_PRINTER_Status
{
    bool drawer_open_close_signal;
    bool printer_status_offline;
    bool printer_cover_open;
    bool paper_being_fed_by_button;
    bool printing_being_stopped;
    bool auto_cutter_error_occurred;
    bool unrecoverable_error_occurred;
    bool auto_recoverable_error_occurred;
    bool sensor_paper_near_end;
    bool sensor_paper_not_present;
} EL_PRINTER_Status;

typedef struct EL_PRINTER_CustomStatus
{
    bool open_cover;
    bool out_of_paper;
    bool cutter_error;
    bool cash_drawer;
    bool print_head_over_temperature;
    bool error_has_occurred;
} EL_PRINTER_CustomStatus;


typedef enum
{
    ALIGNMENT_LEFT,
    ALIGNMENT_RIGHT,
    ALIGNMENT_CENTER
} EL_PRINTER_Alignment;


typedef enum
{
    FONT_TYPE_A,
    FONT_TYPE_B
} EL_PRINTER_FontType;


typedef enum
{
    FONT_SIZE_1,
    FONT_SIZE_2,
    FONT_SIZE_3,
    FONT_SIZE_4,
    FONT_SIZE_5,
    FONT_SIZE_6,
    FONT_SIZE_7,
    FONT_SIZE_8
} EL_PRINTER_FontSize;


typedef enum
{
    LINE_SPACE_0,
    LINE_SPACE_1,
    LINE_SPACE_2,
    LINE_SPACE_3,
    LINE_SPACE_4
} EL_PRINTER_LineSpace;


typedef struct EL_PRINTER_TextFormat
{
    EL_PRINTER_Alignment alignment;
    EL_PRINTER_LineSpace lineSpace;
    bool bold;
    bool underline;
    EL_PRINTER_FontType fontType;
    int fontSize;
    char* fontPath;
} EL_PRINTER_TextFormat;


typedef enum
{
    BARCODE_TYPE_UPC_A = 65,
    BARCODE_TYPE_UPC_E,
    BARCODE_TYPE_EAN_13,
    BARCODE_TYPE_EAN_8,
    BARCODE_TYPE_CODE_39,
    BARCODE_TYPE_ITF,
    BARCODE_TYPE_CODABAR,
    BARCODE_TYPE_CODE_93,
    BARCODE_TYPE_CODE_128,
    BARCODE_TYPE_QRCODE
} EL_PRINTER_BarcodeType;


typedef enum
{
    BARCODE_SIZE_VERY_SMALL,
    BARCODE_SIZE_SMALL,
    BARCODE_SIZE_MEDIUM,
    BARCODE_SIZE_BIG,
    BARCODE_SIZE_VERY_BIG
} EL_PRINTER_BarcodeSize;


typedef struct
{
    EL_PRINTER_BarcodeType type;
    EL_PRINTER_BarcodeSize size;
    EL_PRINTER_Alignment alignment;
} EL_PRINTER_Barcode;


typedef struct EL_PRINTER_PrintConfig {
    int width;
    int height;
    EL_PRINTER_Alignment alignment;
} EL_PRINTER_PrintConfig;


typedef enum
{
    BITMAP_FORMAT_STANDARD,
    BITMAP_FORMAT_INVERTED
} EL_PRINTER_BitmapFormat;    


typedef struct
{
    EL_PRINTER_BitmapFormat format;
    uint16_t width;
    uint16_t height;
    uint32_t bytesPerPixel;
    uint32_t size;
    uint8_t *data;
} EL_PRINTER_Bitmap;


typedef enum
{
    PAPER_PARTIAL_CUT,
    PAPER_FULL_CUT
} EL_PRINTER_CutType;


typedef enum
{
    BUZZER_TIME_50MS = 1,
    BUZZER_TIME_100MS,
    BUZZER_TIME_150MS,
    BUZZER_TIME_200MS,
    BUZZER_TIME_250MS,
    BUZZER_TIME_300MS,
    BUZZER_TIME_350MS,
    BUZZER_TIME_400MS,
    BUZZER_TIME_450MS
} EL_PRINTER_BuzzerTime;

typedef struct
{
    uint32_t paper_feeded_lines;
    uint32_t printed_lines;
    uint32_t paper_cutting_times;
    uint32_t head_open_times;
    uint32_t paper_out_times;
    uint32_t power_supply_voltage;
    uint32_t head_temperature;
} EL_PRINTER_Statistics;

typedef struct
{
    int fontSize;
    EL_PRINTER_Alignment Alignment;
    uint8_t lineSpace;
} EL_PRINTER_TableFormat;

typedef struct
{
    char *nomeItem;
    char *qtd;
    char *precoUnitario;
    char *precoTotal;
}EL_PRINTER_ListaItens;

typedef struct 
{
    char *nomeFantasia;
    char *razaoSocial;
    char *endereco;
    char *cnpj;
    char *ieNumber;
    char *imNumber;
    char *data;
    char *nomeCliente;
    char *cpf;
    char *extratoNo;
    char *sat;
    char *subtotal;
    char *taxaServico;
    char *desconto;
    char *total;
    char *vouncher;
    char *dinheiro;
    char *totalPago;
    char *troco;
    char *numeroPedido;
    char *propaganda;
    unsigned short tamanhoListaItens;
} EL_PRINTER_Coupon;


/**
 * @brief This function connect the printer based on chosen interface
 * 
 * @param[in] connect_interface interface e.g. RS232, TCPIP, USB
 * @return EL_e_Ret 
 */
EL_e_Ret EL_PRINTER_Connect(EL_PRINTER_Interface connect_interface, ...);

/**
 * @brief Print a simple text
 * 
 * @param[in] text Text to print
 * @return EL_e_Ret 
 */
EL_e_Ret EL_PRINTER_PrintSimpleText(String text);

/**
 * @brief Print a formatted text
 * 
 * @param[in] ref Text format to apply
 * @param[in] text Text to print
 * @return EL_e_Ret 
 */
EL_e_Ret EL_PRINTER_PrintText(EL_PRINTER_TextFormat ref, String text);
EL_e_Ret EL_PRINTER_PrintFormattedText(EL_PRINTER_TextFormat ref, String text);

/**
 * @brief Print a formatted text
 * @param[in] offset The offset to apply to the text
 * @param[in] ref Text format to apply
 * @param[in] text Text to print
 * @return EL_e_Ret 
 */
EL_e_Ret EL_PRINTER_PrintFormattedTextEx(int offset, EL_PRINTER_TextFormat ref, String text);
/**
 * @brief This function gets the current status of printer, based on escpos standard specification
 * 
 * @param[out] status The variable that will store the status
 * @return EL_e_Ret 
 */
EL_e_Ret EL_PRINTER_GetStatus(EL_PRINTER_Status *status);

/**
 * @brief This function scrolls the paper
 * 
 * @param[in] lines Lines to scroll the paper
 * @return EL_e_Ret 
 */
EL_e_Ret EL_PRINTER_ScrollPaper(int lines);

/**
 * @brief Get the paper usage
 * 
 * @param[in] usage Lines of paper usage
 */
void EL_PRINTER_GetPaperUsage(int* usage);

/**
 * @brief Reset the paper usage
 * 
 */
void EL_PRINTER_ResetPaperUsage(void);

/**
 * @brief Print a barcode
 * 
 * @param[in] barcode The barcode properties to apply
 * @param[in] data The data to print as a barcode
 * @return EL_e_Ret 
 */
EL_e_Ret EL_PRINTER_PrintBarcode(EL_PRINTER_Barcode barcode, String data);

/**
 * @brief This functions cuts the paper
 * 
 * @param[in] cut_type The type of cut to be performed
 * @return EL_e_Ret 
 */
EL_e_Ret EL_PRINTER_ExecutePaperCut(EL_PRINTER_CutType cut_type);

/**
 * @brief This function activates the printer buzzer
 * 
 * @param[in] time The time of application of power to the buzzer
 * @param[in] cycles The times to repeat the application of power
 * @return EL_e_Ret 
 */
EL_e_Ret EL_PRINTER_ActivateBuzzer(EL_PRINTER_BuzzerTime time, int cycles);

/**
 * @brief This function gets a custom status that is more understandable than the getstatus function
 * 
 * @param[out] status The variable that will store the status
 * @return EL_e_Ret 
 */
EL_e_Ret EL_PRINTER_GetCustomStatus(EL_PRINTER_CustomStatus* status);

/**
 * @brief This function gets the statistics from printer
 * 
 * @param[out] statistics Store the statistics from printer see EL_PRINTER_Statistics to more specific datas
 * @return EL_e_Ret 
 */
EL_e_Ret EL_PRINTER_GetStatistics(EL_PRINTER_Statistics* statistics);

/**
 * @brief Sets the printer density
 * 
 * @param[in] density The density of the printer to apply
 * @return EL_e_Ret 
 */
EL_e_Ret EL_PRINTER_SetDensity(int density);

/**
 * @brief Opens the cash drawer
 * 
 * @return EL_e_Ret 
 */
EL_e_Ret EL_PRINTER_OpenCashDrawer(void);

/**
 * @brief This function prints a table as an image
 * 
 * @param[in] rows_num The number of rows of the rows matrix
 * @param[in] cols_num The number of columns of both matrixes
 * @param[in] header The vector or matrix of strings with the table header
 * @param[in] rows The string matrix with the rows content
 * @return see EL_e_Ret 
 */
EL_e_Ret EL_PRINTER_PrintTable(size_t rows_num, size_t cols_num, EL_Header* header, EL_Row rows);

/**
 * @brief This function prints a table as an image
 * 
 * @param[in] table_format A structure containing the table settings
 * @param[in] rows_num The number of rows of the rows matrix
 * @param[in] cols_num The number of columns of both matrixes
 * @param[in] header The vector or matrix of strings with the table header
 * @param[in] rows The string matrix with the rows content
 * @return see EL_e_Ret 
 */
EL_e_Ret EL_PRINTER_PrintTableEx(EL_PRINTER_TableFormat table_format ,size_t rows_num, size_t cols_num, EL_Header* header, EL_Row rows);

/**
 * @brief This function print a coupon
 * 
 * @param coupon The fields to be filled 
 * @param[in] lista_itens The list of items it can be an array of items
 * @return EL_e_Ret 
 */
EL_e_Ret EL_PRINTER_PrintCoupon(EL_PRINTER_Coupon coupon, EL_PRINTER_ListaItens *lista_itens);

/**
 * @brief This function store the value of density in density param
 * 
 * @param[out] density The variable that will store the value of density
 * @return EL_e_Ret 
 */
EL_e_Ret EL_PRINTER_GetDensity(int* density);

/**
 * @brief This function converts an image to monochromatic
 * 
 * @param[in] bitmap Input BMP image which will be read
 * @param[out] output Output BMP image which will be written
 * @param[in] threshold Intensity threshold for the conversion algorithm
 * @param[in] format Standard or inverted image parameter
 * @return EL_e_Ret
 */
EL_e_Ret EL_IMAGE_ToMonochromatic(EL_PRINTER_Bitmap bitmap, EL_PRINTER_Bitmap *output, uint8_t threshold, EL_PRINTER_BitmapFormat format);

/**
 * @brief This function converts an image to monochromatic
 * 
 * @param[in] bitmap Input BMP image which will be read
 * @param[out] output Output BMP image which will be written
 * @param[in] threshold Intensity threshold for the conversion algorithm
 * @param[in] format Standard or inverted image parameter
 * @return EL_e_Ret
 */
EL_e_Ret EL_IMAGE_ToVertical(EL_PRINTER_Bitmap bitmap, EL_PRINTER_Bitmap *output, uint8_t threshold, EL_PRINTER_BitmapFormat format);

/**
 * @brief This function reads a image and stores it in image param
 * 
 * @param[in] file Path to the file to read
 * @param[out] image Image to store
 * @return EL_e_Ret 
 */
EL_e_Ret EL_IMAGE_ReadImage(String file, EL_PRINTER_Bitmap* bitmap);

/**
 * @brief This function prints an image
 * 
 * @param[in] print_config Structure containing the settings for the image
 * @param[in] bitmap The struct with the input image data
 * @return see EL_e_Ret 
 */
EL_e_Ret EL_PRINTER_PrintImage(EL_PRINTER_PrintConfig print_config, EL_PRINTER_Bitmap bitmap);

/**
 * @brief This function prints an image
 * 
 * @param[in] offset The horizontal offset to apply
 * @param[in] print_config Structure containing the settings for the image
 * @param[in] bitmap The struct with the input image data
 * @return see EL_e_Ret 
 */
EL_e_Ret EL_PRINTER_PrintImageEx(int offset, EL_PRINTER_PrintConfig print_config, EL_PRINTER_Bitmap bitmap);

/**
 * @brief This function prints an image with autoresize
 * 
 * @param[in] bitmap The struct with the input image data
 * @return see EL_e_Ret 
 */
EL_e_Ret EL_PRINTER_PrintImageAutoResize(EL_PRINTER_Bitmap bitmap);

/**
 * @brief This function prints HTML code as an image
 * 
 * @param[in] html The string containing th HTML piece of code
 * @return see EL_e_Ret 
 */
EL_e_Ret EL_PRINTER_PrintHtml(EL_PRINTER_HTML html);

/**
 * @brief This function prints HTML code as an image
 * 
 * @param[in] print_config Structure containing the settings for the HTML
 * @param[in] html The string containing th HTML piece of code
 * @return see EL_e_Ret 
 */
EL_e_Ret EL_PRINTER_PrintHtmlEx(EL_PRINTER_PrintConfig print_config, EL_PRINTER_HTML html);


#ifdef __cplusplus
    }
#endif 


    #define _EASYLAYER_H_
#endif

