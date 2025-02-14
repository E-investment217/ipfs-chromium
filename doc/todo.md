# TODO list

## Upstreaming
  - Link to blog in existing [Chromium ticket](https://bugs.chromium.org/p/chromium/issues/detail?id=1440503)
  - Intent to intent to prototype precursor emails
  - Intent to prototype
  - [ChromiumStyle](https://chromium.googlesource.com/chromium/src/+/main/styleguide/c++/c++.md)
## Documentation
  - Publish blog
  - Document re-use of library/ipfs_client classes (doxygen/cldoc/doxypress/standardese?)
  - Update design.md to as-implemented
## Maintainability
  - Rename classes to better fit their responsibility (see class-level doc for inspiration)
## Production features
  - User settings
  - MDNS discovery of gateways
## QoI
  - Persist promote/demote (perhaps integrated with user settings)
  - Real URLLoader (not just Simple*) for gateway requests (SetPriority, pause, etc.)
  - Implement SetPriority, having it Scheduler parameters
  - Other hash algos
  - Other multibase encodings
  - IPNS name resolution - receive multiple records and pick highest sequence # (partial)
  - Etag
  - Resolve identity CIDs internally
  - Different headers for IPNS name resolution requests if they came from cache
  - IPNS recursion limit
## Dev QoL
  - Docker builds verifying every documented build approach
  - Github Action release including uploading library artifacts
  - Discovery doesn't really belong in gateway_requests.cc
  - Streamline Windows release, e.g. package_browser 
  - library published in Conan
  - Publish binaries in Conan
## Features
  - .eth resolution
