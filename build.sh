#!/bin/bash

./bin/gn gen out
./bin/ninja -v -C out
