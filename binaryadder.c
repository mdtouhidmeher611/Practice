module full_adder (sum, carry, a, b, cin);
    output sum, carry;
    input a, b, cin;
    wire w1, w2, w3;
    xor g1 (w1, a, b);
    xor g2 (sum, w1, cin);
    and g3 (w2, a, b);
    and g4 (w3, w1, cin);
    or  g5 (carry, w2, w3);
endmodule

module Adder_Subtractor (result, cout, a, b, mode);
    output [3:0] result;
    output cout;
    input [3:0] a, b;
    input mode;
    wire [3:0] b_xor;
    wire c1, c2, c3;
    xor x0 (b_xor[0], b[0], mode);
    xor x1 (b_xor[1], b[1], mode);
    xor x2 (b_xor[2], b[2], mode);
    xor x3 (b_xor[3], b[3], mode);
    full_adder fa0 (result[0], c1, a[0], b_xor[0], mode);
    full_adder fa1 (result[1], c2, a[1], b_xor[1], c1);
    full_adder fa2 (result[2], c3, a[2], b_xor[2], c2);
    full_adder fa3 (result[3], cout, a[3], b_xor[3], c3);
endmodule