# ##############################################################################
# arch/tricore/src/tc3xx/tc397/CMakeLists.txt
#
# Licensed to the Apache Software Foundation (ASF) under one or more contributor
# license agreements.  See the NOTICE file distributed with this work for
# additional information regarding copyright ownership.  The ASF licenses this
# file to you under the Apache License, Version 2.0 (the "License"); you may not
# use this file except in compliance with the License.  You may obtain a copy of
# the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
# WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
# License for the specific language governing permissions and limitations under
# the License.
#
# ##############################################################################

set(SDK_INCDIR
    ${CMAKE_CURRENT_LIST_DIR}/Configurations
    ${CMAKE_CURRENT_LIST_DIR}/Configurations/Ssw
    ${CMAKE_CURRENT_LIST_DIR}/Libraries/iLLD/TC39B/Tricore
    ${CMAKE_CURRENT_LIST_DIR}/Libraries/iLLD/TC39B/Tricore/Cpu/Std
    ${CMAKE_CURRENT_LIST_DIR}/Libraries/iLLD/TC39B/Tricore/Pms/Std
    ${CMAKE_CURRENT_LIST_DIR}/Libraries/iLLD/TC39B/Tricore/Stm/Std
    ${CMAKE_CURRENT_LIST_DIR}/Libraries/iLLD/TC39B/Tricore/Scu/Std
    ${CMAKE_CURRENT_LIST_DIR}/Libraries/iLLD/TC39B/Tricore/Src/Std
    ${CMAKE_CURRENT_LIST_DIR}/Libraries/iLLD/TC39B/Tricore/Stm/Timer
    ${CMAKE_CURRENT_LIST_DIR}/Libraries/iLLD/TC39B/Tricore/Cpu/Trap
    ${CMAKE_CURRENT_LIST_DIR}/Libraries/Infra/Platform
    ${CMAKE_CURRENT_LIST_DIR}/Libraries/Infra/Sfr/TC39B/_Reg
    ${CMAKE_CURRENT_LIST_DIR}/Libraries/Infra/Ssw/TC39B/Tricore
    ${CMAKE_CURRENT_LIST_DIR}/Libraries/Service/CpuGeneric)

target_include_directories(arch PRIVATE ${SDK_INCDIR})
target_include_directories(nuttx PRIVATE ${SDK_INCDIR})

set(SDK_CSRCS
    ${CMAKE_CURRENT_LIST_DIR}/Configurations/Ifx_Cfg_Ssw.c
    ${CMAKE_CURRENT_LIST_DIR}/Libraries/iLLD/TC39B/Tricore/Asclin/Std/IfxAsclin.c
    ${CMAKE_CURRENT_LIST_DIR}/Libraries/iLLD/TC39B/Tricore/Cpu/Std/IfxCpu.c
    ${CMAKE_CURRENT_LIST_DIR}/Libraries/iLLD/TC39B/Tricore/Cpu/Trap/IfxCpu_Trap.c
    ${CMAKE_CURRENT_LIST_DIR}/Libraries/iLLD/TC39B/Tricore/_Impl/IfxAsclin_cfg.c
    ${CMAKE_CURRENT_LIST_DIR}/Libraries/iLLD/TC39B/Tricore/_Impl/IfxCif_cfg.c
    ${CMAKE_CURRENT_LIST_DIR}/Libraries/iLLD/TC39B/Tricore/_Impl/IfxCpu_cfg.c
    ${CMAKE_CURRENT_LIST_DIR}/Libraries/iLLD/TC39B/Tricore/_Impl/IfxPort_cfg.c
    ${CMAKE_CURRENT_LIST_DIR}/Libraries/iLLD/TC39B/Tricore/_Impl/IfxStm_cfg.c
    ${CMAKE_CURRENT_LIST_DIR}/Libraries/iLLD/TC39B/Tricore/_PinMap/IfxAsclin_PinMap.c
    ${CMAKE_CURRENT_LIST_DIR}/Libraries/iLLD/TC39B/Tricore/Pms/Std/IfxPmsEvr.c
    ${CMAKE_CURRENT_LIST_DIR}/Libraries/iLLD/TC39B/Tricore/Pms/Std/IfxPmsPm.c
    ${CMAKE_CURRENT_LIST_DIR}/Libraries/iLLD/TC39B/Tricore/Port/Std/IfxPort.c
    ${CMAKE_CURRENT_LIST_DIR}/Libraries/iLLD/TC39B/Tricore/Scu/Std/IfxScuCcu.c
    ${CMAKE_CURRENT_LIST_DIR}/Libraries/iLLD/TC39B/Tricore/Scu/Std/IfxScuEru.c
    ${CMAKE_CURRENT_LIST_DIR}/Libraries/iLLD/TC39B/Tricore/Scu/Std/IfxScuLbist.c
    ${CMAKE_CURRENT_LIST_DIR}/Libraries/iLLD/TC39B/Tricore/Scu/Std/IfxScuRcu.c
    ${CMAKE_CURRENT_LIST_DIR}/Libraries/iLLD/TC39B/Tricore/Scu/Std/IfxScuWdt.c
    ${CMAKE_CURRENT_LIST_DIR}/Libraries/iLLD/TC39B/Tricore/Src/Std/IfxSrc.c
    ${CMAKE_CURRENT_LIST_DIR}/Libraries/iLLD/TC39B/Tricore/Stm/Std/IfxStm.c
    ${CMAKE_CURRENT_LIST_DIR}/Libraries/Infra/Platform/Tricore/Compilers/CompilerTasking.c
    ${CMAKE_CURRENT_LIST_DIR}/Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Infra.c
    ${CMAKE_CURRENT_LIST_DIR}/Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc0.c
    ${CMAKE_CURRENT_LIST_DIR}/Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc1.c
    ${CMAKE_CURRENT_LIST_DIR}/Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc2.c
    ${CMAKE_CURRENT_LIST_DIR}/Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc3.c
    ${CMAKE_CURRENT_LIST_DIR}/Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc4.c
    ${CMAKE_CURRENT_LIST_DIR}/Libraries/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc5.c)

target_sources(nuttx PRIVATE ${SDK_CSRCS})

if(NOT CONFIG_TRICORE_TOOLCHAIN_TASKING)
  target_link_options(nuttx PRIVATE -Xlinker -nostdlib)
else()
  nuttx_add_extra_library(${CMAKE_CURRENT_LIST_DIR}/SW160800-v6.3r1/TriCore/ctc/lib/tc162/cinit.o)
endif()
