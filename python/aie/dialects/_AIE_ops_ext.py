# ./python/aie/dialects/_AIE_ops_ext.py -*- Python -*-

# Copyright (C) 2022, Advanced Micro Devices, Inc.
# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

try:
  from ..mlir.ir import *
except ImportError as e:
  raise RuntimeError("Error loading imports from extension module") from e
