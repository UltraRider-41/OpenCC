/*
 * Open Chinese Convert
 *
 * Copyright 2010-2014 BYVoid <byvoid@byvoid.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "DictEntry.hpp"

using namespace opencc;

size_t DictEntry::NumValues() const {
  return value.IsNull() ? 0 : 1;
}

string DictEntry::ToString() const {
  if (value.IsNull()) {
    return key;
  } else {
    return key + "\t" + value.Get();
  }
}

size_t MultiValueDictEntry::NumValues() const {
  return values.Length();
}

string MultiValueDictEntry::ToString() const {
  // TODO escape space
  size_t i = 0;
  size_t length = values.Length();
  std::ostringstream buffer;
  buffer << Key() << '\t';
  for (const char* value : values) {
    buffer << value;
    if (i < length - 1) {
      buffer << ' ';
    }
    i++;
  }
  return buffer.str();
}