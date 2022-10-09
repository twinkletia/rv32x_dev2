#define READ 1'b0
#define WRITE 1'b1

declare ram_1p interface {
    input address[14];
    input clock;
    input data[8];
    input wren;
    output q[8];
}