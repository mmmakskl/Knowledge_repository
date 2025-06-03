library verilog;
use verilog.vl_types.all;
entity Control is
    generic(
        ZEROS           : integer := 0;
        flush           : integer := 0;
        load_u          : integer := 1;
        getkey          : integer := 2;
        load_t          : integer := 3;
        standby         : integer := 4;
        alarm           : integer := 5;
        counting        : integer := 6;
        suspended       : integer := 7;
        end_count       : integer := 8
    );
    port(
        clk             : in     vl_logic;
        d               : in     vl_logic_vector(9 downto 0);
        reset           : in     vl_logic;
        start           : in     vl_logic;
        stop            : in     vl_logic;
        zero            : in     vl_logic;
        beep            : out    vl_logic;
        clear           : out    vl_logic;
        hold            : out    vl_logic;
        load            : out    vl_logic
    );
end Control;
