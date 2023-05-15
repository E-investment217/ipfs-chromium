# IPFS racing multi-gateway integration for Chromium

## Current state

### Basic demo
![demo.webm](https://human.mypinata.cloud/ipfs/QmUEW38huGWzJHBoDwHwXvxHDwQQLoBPQa2ewJVqCwbAvr?filename=demo.webm)

### What works
* Navigation ipfs://bafy... (CIDv1 ipfs links with host-legal lowercase charset), requested 1 block at a time
    - Only if the pb-dag nodes are directores, whole file, chunked file.
* ipns:// (requests whole files & resources from a gateway)
* Subresources for ipfs, same restrictions as navigation.

### Some important things that don't work
* HAMTShard (and more exotic nodes, but Shard is important for e.g. Wikipedia)
* CIDv0 navigation
* Validation
* Local resolution of IPNS & DNSLink

### Near-term tasks

See [doc/todo.md](doc/todo.md)

## Originally Planned Design

See [doc/original_design.md](doc/original_design.md)

## Building

See [BUILDING.md](BUILDING.md)


## Outstanding Questions
 * More direct interaction with browser cache? 
 * Changes needed to get the Omnibar to prefer treating ipfs://_ as a URL over a search term
 