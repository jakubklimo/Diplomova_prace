<template>
    <header class="md:hidden flex justify-between items-center bg-gray-900 text-white p-4">
        <div class="text-xl font-bold">Race Timer</div>

        <button @click="ui.toggleMenu()" class="p-2">
            <svg v-if="ui.isMenuOpen" class="w-6 h-6 text-white">
                <use href="#icon-xmark" />
            </svg>

            <svg v-else class="w-6 h-6 text-white">
                <use href="#icon-burger" />
            </svg>
        </button>
    </header>

    <transition>
        <div v-if="ui.isMenuOpen" class="md:hidden bg-gray-900 text-white">
            <div class="p-4">
                <NavMenu @click.native="ui.closeMenu" />
            </div>
            <div class="p-4 flex justify-end">
                v{{ version }}
            </div>
        </div>
    </transition>
</template>

<script setup lang="ts">
import { useUiStore } from '../../store';
import NavMenu from './NavMenu.vue';

const version = __APP_VERSION__;
const ui = useUiStore();
</script>