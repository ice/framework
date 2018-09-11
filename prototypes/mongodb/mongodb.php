<?php
namespace MongoDB\BSON;

if (!class_exists(__NAMESPACE__ . '\ObjectID')) {
    class ObjectID {}
}

if (!class_exists(__NAMESPACE__ . '\Regex')) {
    class Regex {}
}

if (!class_exists(__NAMESPACE__ . '\UTCDateTime')) {
    class UTCDateTime {
        public function toDateTime() {}
    }
}
