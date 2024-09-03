# CONTRIBUTING

## How-to
### Setup
- Install dependencies:
It is recomended to use the VSCode with the `.devcontainer`.
If you want to defvelop natively on an Ubuntu 22 distribution, you can run
```bash
./.devcontainer/setup_build_environment_on_ubuntu_22.sh
./.devcontainer/setup_documentation_environment_on_ubuntu_22.sh
```

### Develop
- Format all files of the repository using relevant `pre-commit` hook
```bash
make format
```

- Configure the project
```bash
make configure
```

- Run all tests
```bash
make test
```
### Generate artifacts

- Generate the project documentation
```bash
make documentation
```

- Create a debian package of the project
```bash
make packaging
```

## Project documentation
-
