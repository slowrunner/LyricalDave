#!/usr/bin/env python3

# time_server.py
import datetime
from mcp.server.fastmcp import FastMCP
import easygopigo3

REV_PROTECT_DIODE = 0.6

# Initialize the FastMCP server
mcp = FastMCP("GoPiGo3 Battery")

@mcp.tool()
def get_gopigo3_vbatt() -> str:
    """Get the GoPiGo3 Battery Voltage"""
    egpg = easygopigo3.EasyGoPiGo3()
    return str(egpg.volt()+REV_PROTECT_DIODE)

if __name__ == "__main__":
    mcp.run(transport="stdio")
