#!/bin/bash
set -e
zip -9ojX SuperspySimulator.data  README.md
pushd Platformer
find ./Assets/* | sort | xargs zip -9oX ../SuperspySimulator.data
popd
pushd Clean
find ./Saves/* | sort | xargs zip -9oX ../SuperspySimulator.data
popd