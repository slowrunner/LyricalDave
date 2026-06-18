#!/usr/bin/env python3

# time_server.py
import datetime
from mcp.server.fastmcp import FastMCP

# Initialize the FastMCP server
mcp = FastMCP("Ubuntu System Clock")

@mcp.tool()
def get_system_datetime() -> str:
    """Get the current date and time from the host Ubuntu system clock."""
    return datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")

if __name__ == "__main__":
    mcp.run(transport="stdio")
