# See: https://docs.conan.io/2/reference/conanfile.html

from conan import ConanFile
from conan.tools.build import check_min_cstd
from conan.tools.files import copy
from os import path

class KnowCConan(ConanFile):
    name = "know.c"
    version = "0.0.0"
    description = "The Know Framework for C."
    license = "Unlicense"
    author = "KNOW Project"
    topics = ("ontology", "header-only", "c11")
    homepage = "https://github.com/KnowOntology/know.c"
    url = "https://github.com/KnowOntology/know.c.git"
    languages = "C"
    exports_sources = "src/*"
    no_copy_source = True

    def layout(self):
        self.folders.source = "src"

    def validate(self):
        #check_min_cstd(self, 11) # FIXME: Conan 2.4.1 appears to be defective
        pass

    def package(self):
        copy(self, "*.h", self.source_folder, path.join(self.package_folder, "include"))

    def package_info(self):
        self.cpp_info.bindirs = []
        self.cpp_info.libdirs = []
