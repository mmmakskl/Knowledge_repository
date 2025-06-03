library verilog;
use verilog.vl_types.all;
entity verilog_qs_tester is
    port(
        clk             : out    vl_logic;
        in1             : out    vl_logic_vector(10 downto 0);
        in2             : out    vl_logic_vector(10 downto 0);
        in3             : out    vl_logic_vector(10 downto 0);
        in4             : out    vl_logic_vector(10 downto 0);
        in5             : out    vl_logic_vector(10 downto 0);
        in6             : out    vl_logic_vector(10 downto 0);
        in7             : out    vl_logic_vector(10 downto 0);
        in8             : out    vl_logic_vector(10 downto 0);
        in9             : out    vl_logic_vector(10 downto 0);
        in10            : out    vl_logic_vector(10 downto 0);
        out1            : in     vl_logic_vector(10 downto 0);
        out2            : in     vl_logic_vector(10 downto 0);
        out3            : in     vl_logic_vector(10 downto 0);
        out4            : in     vl_logic_vector(10 downto 0);
        out5            : in     vl_logic_vector(10 downto 0);
        out6            : in     vl_logic_vector(10 downto 0);
        out7            : in     vl_logic_vector(10 downto 0);
        out8            : in     vl_logic_vector(10 downto 0);
        out9            : in     vl_logic_vector(10 downto 0);
        out10           : in     vl_logic_vector(10 downto 0)
    );
end verilog_qs_tester;
