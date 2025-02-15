//===- AIEMLIRModule.cpp ----------------------------------------*- C++ -*-===//
//
// Copyright (C) 2022, Advanced Micro Devices, Inc. All rights reserved.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "mlir/Bindings/Python/PybindAdaptors.h"

#include "aie-c/Dialects.h"
#include "aie-c/Registration.h"

namespace py = pybind11;
using namespace mlir::python::adaptors;

PYBIND11_MODULE(_aieMlir, m) {

  //::aieRegisterAllPasses();

  m.doc() = R"pbdoc(
    AIE MLIR Python bindings
    --------------------------

    .. currentmodule:: _aieMlir

    .. autosummary::
        :toctree: _generate
  )pbdoc";

  m.def(
      "register_dialect",
      [](MlirContext context, bool load) {
        MlirDialectHandle handle = mlirGetDialectHandle__aie__();
        mlirDialectHandleRegisterDialect(handle, context);
        if (load) {
          mlirDialectHandleLoadDialect(handle, context);
        }
      },
      py::arg("context"), py::arg("load") = true);

  // AIE types bindings
  mlir_type_subclass(m, "ObjectFifoType", aieTypeIsObjectFifoType)
      .def_classmethod(
          "get",
          [](py::object cls, MlirType type) {
            return cls(aieObjectFifoTypeGet(type));
          },
          "Get an instance of ObjectFifoType with given element type.",
          py::arg("self"), py::arg("type") = py::none());

  // m.def("_register_all_passes", ::aieRegisterAllPasses);

  m.attr("__version__") = "dev";
}
