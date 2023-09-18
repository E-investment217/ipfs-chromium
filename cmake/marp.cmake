find_program(MARP_EXE NAMES "marp")
if(MARP_EXE)
  set(out "${CMAKE_BINARY_DIR}/doc/html/slides")
  file(MAKE_DIRECTORY "${out}")
  add_custom_target(gen_slides
#    COMMAND "${MARP_EXE}" --pptx --allow-local-files --output "${out}" --input-dir "${CMAKE_SOURCE_DIR}/doc/slides/"
#    COMMAND "${MARP_EXE}"        --allow-local-files --output "${out}" --input-dir "${CMAKE_SOURCE_DIR}/doc/slides/"
    COMMENT "Generated slides from doc/slides/*.md"
    DEPENDS ${doc_targets}
  )
  file(GLOB
      slide_mds
    CONFIGURE_DEPENDS
      doc/slides/*.md
  )
  foreach(slide_md ${slide_mds})
    get_filename_component(slide "${slide_md}" NAME_WE)
    add_custom_target(${slide}
      SOURCES "${slide_md}"
      COMMAND "${MARP_EXE}" --pptx --allow-local-files "${slide_md}" --output "${out}/${slide}.pptx"
      COMMAND "${MARP_EXE}"        --allow-local-files "${slide_md}" --output "${out}/${slide}.html"
    )
    if(DOXYGEN_FOUND AND USE_DOXYGEN)
      add_custom_command(
        TARGET "${slide}"
        POST_BUILD
        COMMAND cmake -E copy "${out}/${slide}.html" "${CMAKE_BINARY_DIR}/doc/html/md_doc_slides_${slide}.html"
      )
    endif()
    add_dependencies(gen_slides "${slide}")
  endforeach()
  list(APPEND doc_targets gen_slides)
endif()
