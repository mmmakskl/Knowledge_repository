library verilog;
use verilog.vl_types.all;
entity verilog_qs is
    port(
        clk             : in     vl_logic;
        in1             : in     vl_logic_vector(10 downto 0);
        in2             : in     vl_logic_vector(10 downto 0);
        in3             : in     vl_logic_vector(10 downto 0);
        in4             : in     vl_logic_vector(10 downto 0);
        in5             : in     vl_logic_vector(10 downto 0);
        in6             : in     vl_logic_vector(10 downto 0);
        in7             : in     vl_logic_vector(10 downto 0);
        in8             : in     vl_logic_vector(10 downto 0);
        in9             : in     vl_logic_vector(10 downto 0);
        in10            : in     vl_logic_vector(10 downto 0);
        out1            : out    vl_logic_vector(10 downto 0);
        out2            : out    vl_logic_vector(10 downto 0);
        out3            : out    vl_logic_vector(10 downto 0);
        out4            : out    vl_logic_vector(10 downto 0);
        out5            : out    vl_logic_vector(10 downto 0);
        out6            : out    vl_logic_vector(10 downto 0);
        out7            : out    vl_logic_vector(10 downto 0);
        out8            : out    vl_logic_vector(10 downto 0);
        out9            : out    vl_logic_vector(10 downto 0);
        out10           : out    vl_logic_vector(10 downto 0)
    );
end verilog_qs;
