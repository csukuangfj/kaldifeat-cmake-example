# Introduction

This project demonstrates how to use [kaldifeat][kaldifeat]
in CMake-based projects with C++.

It does not describe the C++ APIs of [kaldifeat][kaldifeat]. It only shows
how to use [kaldifeat][kaldifeat] in your CMake-based projects with C++.

# Usage

First, please refer to <https://csukuangfj.github.io/kaldifeat/>
to install [kaldifeat][kaldifeat].

**Note**: You need to install PyTorch before you can install [kaldifeat][kaldifeat].

After installing [kaldifeat][kaldifeat], you can run this project
with the following commands:

```bash
export Torch_DIR=$(python -c 'import torch; print(torch.utils.cmake_prefix_path)')
export kaldifeat_DIR=$(python -c 'import kaldifeat; print(kaldifeat.cmake_prefix_path)')

git clone https://github.com/csukuangfj/kaldifeat-cmake-example
cd kaldifeat-cmake-example
mkdir build
cd build
cmake ..
make
./main
```

You will get the following output after executing `./main`:

```
frame_opts:
samp_freq: 16000
frame_shift_ms: 10
frame_length_ms: 25
dither: 1
preemph_coeff: 0.97
remove_dc_offset: 1
window_type: povey
round_to_power_of_two: 1
blackman_coeff: 0.42
snip_edges: 1
max_feature_vectors: -1


mel_opts:
num_bins: 23
low_freq: 20
high_freq: 0
vtln_low: 100
vtln_high: -500
debug_mel: 0
htk_mode: 0

use_energy: 0
energy_floor: 0
raw_energy: 1
htk_compat: 0
use_log_fbank: 1
use_power: 1
device: cpu

```


[kaldifeat]: https://github.com/csukuangfj/kaldifeat
